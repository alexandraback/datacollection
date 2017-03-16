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

// i = 2
// j = 4
// k = 8

int sign(int x) {
    if (x == 0) return 1;
    return (x > 0) - (x < 0);
}

int multiplicate(int a, int b) {
    if (a == 1 || b == 1 || a == -1 || b == -1) {
        return a * b;
    }
    if (abs(a) == abs(b)) {
        return -1 * sign(a * b);
    }
    int r = a * b;
    //qDebug() << "a" << a << "b" << b << "r" << r << "sign" << sign(r);
    switch(abs(r)) {
        case 8: return sign(r) * 8 * ((abs(a) == 2) ? 1 : -1);
        case 16: return sign(r) * 4 * ((abs(a) == 2) ? -1 : 1);
        case 32: return sign(r) * 2 * ((abs(a) == 4) ? 1 : -1);
    default: return 0;
    }
}

int charToInt(QChar c) {
    if (c == 'i') {
        return 2;
    } else if (c == 'j') {
        return 4;
    } else {
        return 8;
    }
}

QString intToQChar(int i) {
    switch(i) {
    case 2: return "i";
    case 4: return "j";
    case 8: return "k";
    case -2: return "-i";
    case -4: return "-j";
    case -8: return "-k";
    default: return QString::number(i);
    }
}

QString getAnswer(int Ln, int repeat, QString input) {
    if (is_debug) {
        //qDebug() << "start getAnswer";
    }
    if (Ln == 1) {
        return "NO";
    }

    QList<QPair<int, int>> answer;
    answer.append(QPair<int, int>(1, 0));
    int curr_int, loc_res, loc_step;
    QString processed;

    bool with_i = false, with_j = false, with_k = false;
    int int_cnt = 0;
    int loc_res_add, loc_step_add;
    for (int i = 0; i < repeat; ++i) {
        for (int j = 0; j < Ln; ++j) {
            //processed.append(input.at(j));
            curr_int = charToInt(input.at(j));
            //if (is_debug) qDebug() << "char" << input.at(j) << "char_int" << curr_int;
            //glob_res = multiplicate(glob_res, curr_int);
            for (int k = 0, Ln = answer.count(); k < Ln; ++k) {
                if (answer.at(k).second == 3) {
                    answer.replace(k, QPair<int, int>(-13, 3));
                    continue;
                }
                loc_step_add = -1;
                loc_res = multiplicate(answer.at(k).first, curr_int);
                loc_step = answer.at(k).second;
                //if (is_debug) qDebug() << "answer" << k << "curr_result" << intToQChar(answer.at(k).first) << "loc_res" << intToQChar(loc_res) << "answer step" << loc_step;

                if (loc_res == 2 && loc_step == 0) {
                    answer.replace(k, QPair<int, int>(1, 1));
                    loc_res_add = loc_res;
                    loc_step_add = 0;
                } else if (loc_res == 4 && loc_step == 1) {
                    answer.replace(k, QPair<int, int>(1, 2));
                    loc_res_add = loc_res;
                    loc_step_add = 1;
                } else if (loc_res == 8 && loc_step == 2) {
                    answer.replace(k, QPair<int, int>(loc_res, 3));
                    loc_res_add = loc_res;
                    loc_step_add = 2;
                } else {
                    answer.replace(k, QPair<int, int>(loc_res, loc_step));
                }
                if (loc_step_add != -1) {
                    answer.append(QPair<int, int>(loc_res_add, loc_step_add));
                }
            }
            for (int k = answer.count() -1; k >= 0; --k) {
                if (answer.at(k).first == -13) {
                    continue;
                }
                for (int kk = k - 1; kk >= 0; --kk) {
                    if (answer.at(k).first == answer.at(kk).first && answer.at(k).second == answer.at(kk).second) {
                        answer.replace(kk, QPair<int, int>(-13, 3));
                    }
                }
            }
            for (int k = answer.count() -1; k >= 0; --k) {
                if (answer.at(k).first == -13) {
                    answer.removeAt(k);
                }
            }
            /*if ((i + 1) * j >= 20) {
                if (is_debug) qDebug() << processed << answer;
                return "DEBUG";
            }*/

            if (i == 0) {
                if (!with_i && input.at(j) == 'i') {
                    with_i = true;
                    ++int_cnt;
                }
                if (!with_j && input.at(j) == 'j') {
                    with_j = true;
                    ++int_cnt;
                }
                if (!with_k && input.at(j) == 'k') {
                    with_k = true;
                    ++int_cnt;
                }
            }
        }

        if (int_cnt == 1) {
            return "NO";
        }
    }

    for (int k = 0, Ln = answer.count(); k < Ln; ++k) {
        if (answer.at(k).first == 8 && answer.at(k).second == 3) {
            return "YES";
        }
    }
    return "NO";
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
    int repeat, Ln;
/*
    int x1, x2;
    for(int i = -4; i < 4; ++i) {
        //if (i == 0) {continue; }
        x1 = i == -4 ? -1 : sign(i) * pow(2, abs(i));
        for(int j = -4; j < 4; ++j) {
            //if (j == 0) {continue; }
            x2 = j == -4 ? -1 : sign(j) * pow(2, abs(j));
            qDebug() << intToQChar(x1) << "*" << intToQChar(x2) << "=" <<intToQChar(multiplicate(x1, x2));
        }
    }
    return 0;*/

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
        if (Idx % 2 == 1) {
            //qDebug() << Idx << line;
            sl = line.split(" ");
            Ln = sl.at(0).toInt();
            repeat = sl.at(1).toInt();
        } else {
            answer = "Case #" + QString::number(++CaseNum) + ": " + getAnswer(Ln, repeat, line);
            out << answer;
            endl(out);
            if (is_debug) {
                qDebug() << answer;
            }
        }
        finish = QDateTime::currentDateTime();
        if (is_debug) {
            qDebug() << "LineProcessed" << finish.toTime_t() - start.toTime_t();
        }

    }
    return 0;
    //return a.exec();
}
