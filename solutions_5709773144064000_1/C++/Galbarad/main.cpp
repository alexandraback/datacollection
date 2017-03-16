#include <QCoreApplication>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QDebug>

#define ARRAY_LENGTH 4
#define COOKIE_SPEED 2

bool is_debug = false;

QString getAnswer(float C, float F, float X) {
    if (is_debug) {
        qDebug() << "start getAnswer " << C << ", " << F << ", " << X;
    }
    double MinT = X / COOKIE_SPEED;
    if (is_debug) {
        qDebug() << "inital T " << MinT;
    }
    //float T, b, k;
    double T;
    double PrevT = C / COOKIE_SPEED;
    if (is_debug) {
        qDebug() << "inital PrevT " << PrevT;
    }
    for (int i = 1, Ln = floor(X / C); i <= Ln; ++i) {
        T = X / (COOKIE_SPEED + i * F) + PrevT;
        PrevT += C / (COOKIE_SPEED + i * F);
        if (is_debug) {
            qDebug() << "T = " << T << " MinT = " << MinT << " PrevT: " << PrevT;
        }
        if (MinT > T) {
            MinT = T;
        }
    }
    /*for (int i = 1, Ln = floor(X / C); i <= Ln; ++i) {
        k = 2 + (i * F);
        b = -PrevT * k;
        PrevT = (C - b) / k;
        T = (X - b) / k;
        if (is_debug) {
            qDebug() << "k = " << k << " b = " << b << " PrevT = " << PrevT << " T = " << T << " MinT = " << MinT;
        }
        if (MinT > T) {
            MinT = T;
        }
    }*/
    return QString::number(MinT, 'f', 7);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList params = QCoreApplication::arguments();
    if (params.count() < 3) {
        return 1;
    }

    QFile file_in(params.at(1)); // this is a name of a file text1.txt sent from main method
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
    QStringList SplitedLine;

    while (!in.atEnd()) {
        line = in.readLine();
        if (++Idx == 0 && is_debug) {
            qDebug() << "Input case count " << line;
            continue;
        }
        SplitedLine = line.split(" ");
        out << "Case #" << ++CaseNum << ": " << getAnswer(SplitedLine.at(0).toFloat(), SplitedLine.at(1).toFloat(), SplitedLine.at(2).toFloat());
        endl(out);
    }
    return 0;
    //return a.exec();
}
