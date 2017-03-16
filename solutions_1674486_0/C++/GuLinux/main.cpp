#include <QtCore/QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>

#include <QMap>
#include <QList>

/********************************************************************************
  The following code is using Qt 4.8 library, publicly available at Nokia website
  http://qt-project.org/downloads

  QMake file content:

QT       += core
QT       -= gui
TARGET = CodeJam
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app
SOURCES += main.cpp

*********************************************************************************/

class Clazz {
public:
    Clazz(ulong classNumber) : classNumber(classNumber) {}
    const ulong classNumber;
    QList<ulong> dependencies;

    ulong pathsTo(const Clazz &other, QList<Clazz> classes) {
        ulong result=0;
        foreach(ulong dep, dependencies) {
            if(dep==other.classNumber) {
                result++;
            } else {
                Clazz next = classes[dep-1];
                result+= next.pathsTo(other, classes);
            }
        }
        return result;
    }

    inline friend QDebug operator<< (QDebug s, const Clazz* cfgKey) {
        s.nospace() << "Number=" << cfgKey->classNumber << ", dependencies: [" << cfgKey->dependencies << "]";
        return s.space();
    }
    inline friend QDebug operator<< (QDebug s, const Clazz& cfgKey) {
        return s << &cfgKey;
    }

};


QString solveCase(QTextStream *input) {
    ulong numOfClasses = input->readLine().toULong();
    QList<Clazz> classes;
    QList<Clazz> startClasses;
    QList<Clazz> destinationClasses;
    for(ulong curr=0; curr<numOfClasses; curr++) {
        QStringList dependencies = input->readLine().split(' ');
        Clazz clazz(curr+1);
        ulong numOfDependencies = dependencies.takeFirst().toULong();

        foreach(const QString dep, dependencies) {
            clazz.dependencies << dep.toULong();
        }
        classes << clazz;

        if(numOfDependencies==0) {
            destinationClasses << clazz;
        } else {
            startClasses << clazz;
        }
    }

    foreach(Clazz startClass, startClasses) {
        foreach(Clazz endClass, destinationClasses) {
            if(startClass.pathsTo(endClass, classes) >1) return "Yes";
        }
    }
    return "No";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStringList params = a.arguments();
    QString filename = params.at(1);
    QFile input(filename);
    input.open(QFile::ReadOnly);
    QTextStream iStream(&input);
    QTextStream output(stdout);
    int cases = iStream.readLine().toInt();
    for(int i=0; i<cases; i++) {
        output << QString("Case #%1: %2\n").arg(i+1).arg(solveCase(&iStream));
    }

    input.close();
    return 0;

}
