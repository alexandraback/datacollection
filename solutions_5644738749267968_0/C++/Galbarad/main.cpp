#include <QCoreApplication>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QDebug>

#define ARRAY_LENGTH 4
#define COOKIE_SPEED 2

bool is_debug = false;

QString getAnswerEx(QList<double>& nb, QList<double>& kb1, QList<double>& kb2) {
    if (is_debug) {
        qDebug() << "Naomi briks " << nb;
    }
    if (is_debug) {
        qDebug() << "Ken briks 1 " << kb1;
    }
    int W = nb.count(), CW = W;
    double kf;
    for (int i = 0, Ln = nb.count(); i < Ln; ++i) {
         if (nb.at(i) < kb1.first()) {
            kf = kb1.takeLast();
         } else {
            kf = kb1.takeFirst();
         }
         if (nb.at(i) < kf) {
             --CW;
         }
    }
    if (is_debug) {
        qDebug() << "Ken briks 2 " << kb2;
    }
    for (int i = nb.count() - 1; i >= 0; --i) {
        if (nb.at(i) > kb2.last()) {
           kf = kb2.takeFirst();
        } else {
           kf = kb2.takeLast();
        }
        if (nb.at(i) < kf) {
            --W;
        }
    }
    /*foreach(double naomi_brick, nb) {
        foreach(double ken_brick, kb) {

        }
    }*/
    return QString("%1 %2").arg(CW).arg(W);
}

QString getAnswer(QStringList nb, QStringList kb) {
    QList<double> NaomiBriks;
    foreach(QString item, nb) {
        NaomiBriks.append(item.toDouble());
    }
    QList<double> KenBriks1;
    QList<double> KenBriks2;
    foreach(QString item, kb) {
        KenBriks1.append(item.toDouble());
    }
    qSort(NaomiBriks);
    qSort(KenBriks1);
    foreach(double item, KenBriks1) {
        KenBriks2.append(item);
    }

    return getAnswerEx(NaomiBriks, KenBriks1, KenBriks2);
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
    QStringList NaomiBriks;
    QStringList KenBriks;

    while (!in.atEnd()) {
        line = in.readLine();
        if (++Idx == 0 && is_debug) {
            qDebug() << "Input case count " << line;
            continue;
        }
        if (Idx % 3 == 1 && is_debug) {
            qDebug() << "brick count " << line;
            continue;
        }
        if (Idx % 3 == 2) {
            if (is_debug) {
                qDebug() << "Naomi bricks " << line;
            }
            NaomiBriks = line.split(" ");
        }
        if (Idx % 3 == 0) {
            if (is_debug) {
                qDebug() << "Ken bricks " << line;
            }
            KenBriks = line.split(" ");

            out << "Case #" << ++CaseNum << ": " << getAnswer(NaomiBriks, KenBriks);
            endl(out);
        }
    }
    return 0;
}
