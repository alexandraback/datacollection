#include <QCoreApplication>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QDebug>
#include <QtGlobal>
#include <QDateTime>
#include <QList>
#include <QMap>

bool is_debug = false;


QString getAnswer(QStringList D) {
    if (is_debug) {
        qDebug() << "start getAnswer";
    }
    QList<int> d_cnt;
    int Ln = D.count(), min = 0, max = 0, curr_num;
    for (int i = 0; i < Ln; ++i) {
        curr_num = D.at(i).toInt();
        d_cnt.append(curr_num);
        if (max < curr_num) {
            max = curr_num;
        }

    }
    qSort(d_cnt);
    qDebug() << d_cnt;
    min = max;
    int curr_min, move_cnt;
    for (int i = 1; i <= max; ++i) {
        // curr_min = max - (max - i) + pancake_per_min[i];
        move_cnt = 0;
        for (int j = Ln - 1; j >= 0; --j) {
            curr_num = d_cnt.at(j);
            if (curr_num < i) {
                break;
            }
            curr_num -= i;
            move_cnt += curr_num / i + ((curr_num % i) != 0 ? 1 : 0) ;
        }
        curr_min = i + move_cnt;

        qDebug() << "i" << i << "move_cnt" << move_cnt << "curr_min" << curr_min << "min" << min;
        if (curr_min < min) {
            min = curr_min;
        }
    }

    return QString::number(min);
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

    //QDateTime start;
    //QDateTime finish;
    while (!in.atEnd()) {
        line = in.readLine();
        if (++Idx == 0) {
            if (is_debug) qDebug() << "Input case count " << line;
            continue;
        }
        if (is_debug) {
            qDebug() << "Current index " << Idx;
        }
        //start = QDateTime::currentDateTime();
        if (Idx % 2 == 0) {
            sl = line.split(" ");
            answer = "Case #" + QString::number(++CaseNum) + ": " + getAnswer(sl);
            out << answer;
            endl(out);
            if (is_debug) {
                qDebug() << answer;
            }
        }
        //finish = QDateTime::currentDateTime();
        //if (is_debug) {
            //qDebug() << "LineProcessed" << finish.toTime_t() - start.toTime_t();
        //}

    }
    return 0;
    //return a.exec();
}
