#include <QCoreApplication>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QDebug>
#include <QtGlobal>
#include <QDateTime>

bool is_debug = false;


QString getAnswer(int max_sl, QString audience) {
    if (is_debug) {
        qDebug() << "start getAnswer" << max_sl << audience;
    }
    int need_cnt = 0, curr_cnt = 0, stand_cnt = 0;
    for (int i = 0; i <= max_sl; ++i) {
      curr_cnt = audience.at(i).digitValue();
      if (curr_cnt == 0) {
          continue;
      }
      if (i > stand_cnt) {
        need_cnt += i - stand_cnt;
        stand_cnt = i;
      }

      stand_cnt += curr_cnt;
    }

    return QString::number(need_cnt);
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

    QDateTime start;
    QDateTime finish;
    while (!in.atEnd()) {
        line = in.readLine();
        if (++Idx == 0) {
            if (is_debug) qDebug() << "Input case count " << line;
            continue;
        }
        if (is_debug) {
            qDebug() << "Current index " << Idx;
        }
        start = QDateTime::currentDateTime();
        sl = line.split(" ");
        out << "Case #" << ++CaseNum << ": " << getAnswer(sl.at(0).toInt(), sl.at(1));
        endl(out);
        finish = QDateTime::currentDateTime();
        if (is_debug) {
            qDebug() << "LineProcessed" << finish.toTime_t() - start.toTime_t();
        }

    }
    return 0;
    //return a.exec();
}
