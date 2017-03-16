#include <QCoreApplication>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QDebug>
#include <QtGlobal>
#include <QDateTime>
#include <QList>
#include <QMap>
#include <QPair>

bool is_debug = false;

QString getAnswer(int X, int R, int C) {
    if (is_debug) {
       // qDebug() << "start getAnswer" << X << R << C;
    }

    if ((R * C) % X != 0) {
        return "RICHARD";
    }

    if (R * C < X) {
        return "RICHARD";
    }

    int min = R > C ? C : R;
    if (X >= min + 2) {
        return "RICHARD";
    }

    return "GABRIEL";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList params = QCoreApplication::arguments();
    if (params.count() < 3) {
        return 1;
    }

    qDebug() << params;
    qDebug() << params.at(1);
    QFile file_in(params.at(1));
    if (!file_in.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return 2;
    }

    QTextStream in(&file_in);

    QFile file_out(params.at(2));
    if (!file_out.open(QIODevice::WriteOnly)) {
        return 3;
    }

    is_debug = params.count() > 3 && params.at(3).compare("debug") == 0;

    QTextStream out(&file_out);
    QString line;
    int Idx = -1;
    int CaseNum = 0;
    QStringList sl;
    QString answer;

    QDateTime start;
    QDateTime finish;

    while (!in.atEnd()) {
        line = in.readLine();
        if (++Idx == 0) {
            if (is_debug) qDebug() << "Input case count " << line;
            continue;
        }
        if (is_debug) {
            //qDebug() << "Current index " << Idx;
        }
        start = QDateTime::currentDateTime();
        sl = line.split(" ");
        answer = "Case #" + QString::number(++CaseNum) + ": " + getAnswer(sl.at(0).toInt(), sl.at(1).toInt(), sl.at(2).toInt());
        out << answer;
        endl(out);
        if (is_debug) {
            qDebug() << line << answer;
        }
        finish = QDateTime::currentDateTime();
        if (is_debug) {
            //qDebug() << "LineProcessed" << finish.toTime_t() - start.toTime_t();
        }

    }
    return 0;
    //return a.exec();
}
