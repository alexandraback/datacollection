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

QMap<int, int> M;

QString getAnswer() {
    if (is_debug) {
        qDebug() << "start getAnswer";
    }
    QString res;
    QMapIterator<int, int> i(M);
    while (i.hasNext()) {
        i.next();
        if (i.value() % 2 == 1) {
            if (!res.isEmpty()) {
                res.append(" ");
            }
            res.append(QString::number(i.key()));
        }
    }

    return res;
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

    is_debug = true;//params.count() > 3 && params.at(3).compare("debug") == 0;

    QTextStream out(&file_out);
    QString line;
    int Idx = -1;
    int CaseNum = 0;
    QString answer;

    QDateTime start;
    QDateTime finish;
    QStringList sl;
    int line_type = 0;
    int N = 0;
    int LnCnt = 0;
    int i;

    while (!in.atEnd()) {
        line = in.readLine();
        if (++Idx == 0) {
            if (is_debug) qDebug() << "Input case count " << line;
            continue;
        }
        if (is_debug) {
            qDebug() << "Current index " << Idx << N << line_type << LnCnt << line;
        }
        start = QDateTime::currentDateTime();
        if (Idx == 1) {
            line_type = 1;
            //continue;
        }

        if (line_type == 1) {
            N = line.toInt();
            LnCnt = 2 * N - 1;
            line_type = 2;
            continue;
        }

        if (line_type == 2) {
            sl = line.split(" ");
            foreach(QString s, sl) {
                i = s.toInt();
                if (M.contains(i)) {
                    ++M[i];
                } else {
                    M[i] = 1;
                }
            }
            if (--LnCnt == 0) {
                line_type = 3;
            } else {
                continue;
            }
        }

        if (line_type == 3) {
            answer = "Case #" + QString::number(++CaseNum) + ": " + getAnswer();
            out << answer;
            endl(out);
            if (is_debug) {
                qDebug() << line << answer;
            }
            M.clear();
            line_type = 1;
        }
        finish = QDateTime::currentDateTime();
        if (is_debug) {
            //qDebug() << "LineProcessed" << finish.toTime_t() - start.toTime_t();
        }

    }//*/
    return 0;
    //return a.exec();
}
