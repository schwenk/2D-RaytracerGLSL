#ifndef GLANN_H
#define GLANN_H

#pragma once

#include <QApplication>
#include <QScreen>

#include <QGLShaderProgram>
#include <QGLFunctions>
#include <QOpenGLFramebufferObject>
#include <QGLPixelBuffer>

#include <QApplication>

#include <QBasicTimer>
#include <QTime>
#include <QImage>
#include <QVector>

#include <QtGui/QOpenGLFramebufferObject>
#include <QtGui/QMouseEvent>

#include "scene.h"
#include "playground.h"
#include "Floatbits.h"

class GLANN : public QGLWidget,protected QGLFunctions
{
    Q_OBJECT

public:
    GLANN(unsigned int renderPasses, Scene *renderScene = 0,
          QWidget *parent = 0, QGLWidget *shareWidget = 0);

    QImage getRenderedImage();

protected:

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void timerEvent(QTimerEvent *);

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

private:
    void render();

    void getFeedbackTexture();

    void initShader();
    void initTextures();
    bool initFbo();

    float xTemp = 0;
    float yTemp = 0;

    unsigned int width;
    unsigned int height;

    QBasicTimer timer;


    Scene *mScene;
    QImage *SceneImage;
    QImage *renderedImage;
    QImage *randomImage;

    QGLShaderProgram program;
    QOpenGLFramebufferObject *fbo;

    GLuint pixelsRandom;
    GLint pixelsRenderedImage;
    GLuint pixelsScene;
    unsigned char *renderedImageUCHAR;

    //unsigned int texSize = 512;

    unsigned int numObjects;
    unsigned int mRenderPasses = 0;

    GLuint vboId0;
    GLuint vboId1;
    struct VertexData
    {
        QVector3D position;
        QVector2D texCoord;
    };

};

#endif // GLANN_H
