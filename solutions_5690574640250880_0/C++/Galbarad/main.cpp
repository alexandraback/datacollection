#include <QCoreApplication>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QDebug>

bool is_debug = false;

#define EMPTY_CELL 0
#define START_CELL 1
#define BOMB_CELL 2

#define ARR_SIMPLE_NUMBER_LENGTH 367
int ARR_SIMPLE_NUMBER[ARR_SIMPLE_NUMBER_LENGTH] =
                             {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,
                              163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,
                              337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,
                              521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,
                              719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,
                              929,937,941,947,953,967,971,977,983,991,997,1009,1013,1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,1087,1091,1093,
                              1097,1103,1109,1117,1123,1129,1151,1153,1163,1171,1181,1187,1193,1201,1213,1217,1223,1229,1231,1237,1249,1259,1277,1279,
                              1283,1289,1291,1297,1301,1303,1307,1319,1321,1327,1361,1367,1373,1381,1399,1409,1423,1427,1429,1433,1439,1447,1451,1453,
                              1459,1471,1481,1483,1487,1489,1493,1499,1511,1523,1531,1543,1549,1553,1559,1567,1571,1579,1583,1597,1601,1607,1609,1613,
                              1619,1621,1627,1637,1657,1663,1667,1669,1693,1697,1699,1709,1721,1723,1733,1741,1747,1753,1759,1777,1783,1787,1789,1801,
                              1811,1823,1831,1847,1861,1867,1871,1873,1877,1879,1889,1901,1907,1913,1931,1933,1949,1951,1973,1979,1987,1993,1997,1999,
                              2003,2011,2017,2027,2029,2039,2053,2063,2069,2081,2083,2087,2089,2099,2111,2113,2129,2131,2137,2141,2143,2153,2161,2179,
                              2203,2207,2213,2221,2237,2239,2243,2251,2267,2269,2273,2281,2287,2293,2297,2309,2311,2333,2339,2341,2347,2351,2357,2371,
                              2377,2381,2383,2389,2393,2399,2411,2417,2423,2437,2441,2447,2459,2467,2473,2477};

QString getAnswer(int R, int C, int B) {
    int TotalCellCount = R * C, EmptyCellCount = TotalCellCount - B;

    char Matrix[50][50];
    char init_cell = B == 0 ? EMPTY_CELL : BOMB_CELL;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            Matrix[i][j] = init_cell;
        }
    }

    if (is_debug) {
        qDebug() << "R: " << R << " C: " << C << " B: " << B << " EmptyCellCount: " << EmptyCellCount;
    }

    int MinW = R > C ? C : R;
    for (int fake = 0; fake < 1; ++fake) {
        if (B == 0) {
            break;
        }

        if (EmptyCellCount == 1) {
            Matrix[0][0] = EMPTY_CELL;
            break;
        }

        if (MinW == 1) {
            if (EmptyCellCount == 0) {
                return "Impossible";
            } else {
                if (R == 1) {
                    for (int i = 0; i < C; ++i) {
                        Matrix[0][i] = EMPTY_CELL;
                        if (--EmptyCellCount == 0) {
                            break;
                        }
                    }
                }

                if (C == 1) {
                    for (int i = 0; i < R; ++i) {
                        Matrix[i][0] = EMPTY_CELL;
                        if (--EmptyCellCount == 0) {
                            break;
                        }
                    }
                }

                break;
            }
        }

        if (EmptyCellCount < 4 || EmptyCellCount == 5 || EmptyCellCount == 7) {
            return "Impossible";
        }

        if (MinW == 2) {
            if (EmptyCellCount % 2 == 1) {
                return "Impossible";
            } else {
                if (R == MinW) {
                    for (int j = 0; j < C; ++j) {
                        if (EmptyCellCount <= 0) {
                            break;
                        }
                        for (int i = 0; i < R; ++i) {
                            if (is_debug) {
                                qDebug() << "R==2 " << i << ", " << j << ", " << EmptyCellCount;
                            }
                            Matrix[i][j] = EMPTY_CELL;
                            if (--EmptyCellCount == 0) {
                                break;
                            }
                        }
                        if (EmptyCellCount <= 0) {
                            break;
                        }
                    }
                } else {
                    for (int i = 0; i < R; ++i) {
                        if (EmptyCellCount <= 0) {
                            break;
                        }
                        for (int j = 0; j < C; ++j) {
                            if (is_debug) {
                                qDebug() << "C==2 " << i << ", " << j << ", " << EmptyCellCount;
                            }
                            Matrix[i][j] = EMPTY_CELL;
                            if (--EmptyCellCount == 0) {
                                break;
                            }
                        }
                        if (EmptyCellCount <= 0) {
                            break;
                        }
                    }
                }
            }
        }

        if (MinW == 3) {
            bool is_spec_3 = EmptyCellCount % MinW == 1;
            if (R == MinW) {
                for (int j = 0; j < C; ++j) {
                    if (EmptyCellCount <= 0) {
                        break;
                    }
                    for (int i = 0; i < R; ++i) {
                        if (is_spec_3 && i == R - 1 && (EmptyCellCount == 2)) {
                            continue;
                        }
                        Matrix[i][j] = EMPTY_CELL;
                        if (--EmptyCellCount == 0) {
                            break;
                        }
                    }
                    if (EmptyCellCount <= 0) {
                        break;
                    }
                }
            } else {
                for (int i = 0; i < R; ++i) {
                    if (EmptyCellCount <= 0) {
                        break;
                    }
                    for (int j = 0; j < C; ++j) {
                        if (is_spec_3 && j == C - 1 && (EmptyCellCount == 2)) {
                            continue;
                        }
                        Matrix[i][j] = EMPTY_CELL;
                        if (--EmptyCellCount == 0) {
                            break;
                        }
                    }
                    if (EmptyCellCount <= 0) {
                        break;
                    }
                }
            }
        }

        if (MinW == 4) {
            bool is_spec_case = EmptyCellCount % MinW == 1;
            int lEmptyCellCount = EmptyCellCount;
            bool is_spec_9 = EmptyCellCount == 9;
            if (R == MinW) {
                for (int j = 0; j < C; ++j) {
                    if (EmptyCellCount <= 0) {
                        break;
                    }
                    for (int i = 0; i < R; ++i) {
                        if (is_spec_case && i == R - 1 && (EmptyCellCount == 3 || EmptyCellCount == 2)) {
                            continue;
                        }
                        if (is_spec_9 && i >= 3) {
                            continue;
                        }
                        if (lEmptyCellCount < MinW * 2 + 2 && i >= lEmptyCellCount / 2) {
                            continue;
                        }
                        Matrix[i][j] = EMPTY_CELL;
                        if (--EmptyCellCount == 0) {
                            break;
                        }
                    }
                    if (EmptyCellCount <= 0) {
                        break;
                    }
                }
            } else {
                for (int i = 0; i < R; ++i) {
                    if (EmptyCellCount <= 0) {
                        break;
                    }
                    for (int j = 0; j < C; ++j) {
                        if (is_spec_9 && j >= 3) {
                            continue;
                        }
                        if (lEmptyCellCount < MinW * 2 + 2 && j >= (lEmptyCellCount)/ 2) {
                            continue;
                        }
                        if (is_spec_case && j == C - 1 && (EmptyCellCount == 3 || EmptyCellCount == 2)) {
                            continue;
                        }
                        Matrix[i][j] = EMPTY_CELL;
                        if (--EmptyCellCount == 0) {
                            break;
                        }
                    }
                    if (EmptyCellCount <= 0) {
                        break;
                    }
                }
            }
        }

        if (MinW == 5) {
            bool is_spec_case = EmptyCellCount % MinW == 1;
            bool is_spec_9 = EmptyCellCount == 9;
            bool is_spec_11 = EmptyCellCount == 11;
            int lEmptyCellCount = EmptyCellCount;
            if (is_debug) {
                qDebug() << "R==5 " << is_spec_case << ", " << is_spec_9 << ", " << EmptyCellCount;
            }
            if (R == MinW) {
                for (int j = 0; j < C; ++j) {
                    if (EmptyCellCount <= 0) {
                        break;
                    }
                    for (int i = 0; i < R; ++i) {
                        if (is_debug) {
                            qDebug() << "R==5 " << i << ", " << j << ", " << EmptyCellCount;
                        }
                        if (is_spec_9 && i >= 3) {
                            continue;
                        }
                        if (is_spec_11 && i >= 4) {
                            continue;
                        }
                        if (lEmptyCellCount < MinW * 2 + 2 && i >= lEmptyCellCount / 2) {
                            continue;
                        }
                        if (is_spec_case && i >= R - 1 && (EmptyCellCount == 2)) {
                            continue;
                        }
                        Matrix[i][j] = EMPTY_CELL;
                        if (--EmptyCellCount == 0) {
                            break;
                        }
                    }
                    if (EmptyCellCount <= 0) {
                        break;
                    }
                }
            } else {
                for (int i = 0; i < R; ++i) {
                    if (EmptyCellCount <= 0) {
                        break;
                    }
                    for (int j = 0; j < C; ++j) {
                        if (is_spec_9 && j >= 3) {
                            continue;
                        }
                        if (is_spec_11 && j >= 4) {
                            continue;
                        }
                        if (lEmptyCellCount < MinW * 2 + 2 && j >= (lEmptyCellCount - 2)/ 2) {
                            continue;
                        }
                        if (is_spec_case && j == C - 1 && (EmptyCellCount == 2)) {
                            continue;
                        }
                        Matrix[i][j] = EMPTY_CELL;
                        if (--EmptyCellCount == 0) {
                            break;
                        }
                    }
                    if (EmptyCellCount <= 0) {
                        break;
                    }
                }
            }
        }

        /*if (EmptyCellCount % MinW == 0 && EmptyCellCount / MinW >= 2) {
            break;
        }*/

    }

    QString result;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            switch(Matrix[i][j]) {
                case BOMB_CELL:
                    result.append("*");
                    break;
                default:
                    if (i == 0 && j == 0) {
                        result.append("c");
                    } else {
                        result.append(".");
                    }
                    break;
            }
        }
        if (i != R - 1) {
            result.append("\n");
        }
    }

    return result;
}


QString getAnswer_(int R, int C, int B) {
    if (is_debug) qDebug() << "getAnswer[" << R << "][" << C << "], " << B;
    int EmptyCell = R * C - B - 1;
    int BombCount = B;
    char Matrix[50][50];
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if ((i == 0) && (j == 0)) {
                Matrix[i][j] = START_CELL;
            } else {
                Matrix[i][j] = EMPTY_CELL;
            }
        }
    }

    if (R == 1) {
        for (int i = C - 1; i > 0; --i) {
            Matrix[0][i] = BOMB_CELL;
            if (--BombCount == 0) {
                break;
            }
        }
    }

    if (C == 1) {
        for (int i = R - 1; i > 0; --i) {
            Matrix[i][0] = BOMB_CELL;
            if (--BombCount == 0) {
                break;
            }
        }
    }

    if (R > 1 && C > 1 && EmptyCell < 3) {
        return "Impossible";
    }

    /*if (R > 1 && C > 1) {
        for (int i = 0; i < C; ++i) {
            for (int j = 0; j < C; ++j) {

            }
        }
    }*/
    /*int lR = R, lC = C;
    while(BombCount > 0) {
        if (lR > lC) {
            if (BombCount % lR) {

            }
        } else {

        }
        if (BombCount > lR) {
            for (int i = lR - 1; i >= 0; --i) {
                Matrix[i][j] = BOMB_CELL;
            }
        }
    }*/

    /*if (R > C) {
        for (int i = C - 1; i >= 0; --i) {
            if (BombCount <= 0) {
                break;
            }
            for (int j = R - 1; j >= 0; --j) {
                if (BombCount <= 0) {
                    break;
                }
                if (is_debug) qDebug() << "1 Matrix[" << i << "][" << j << "], BombCount: " << BombCount;
                if (j < 2 && BombCount < 2) {
                    continue;
                }
                Matrix[i][j] = BOMB_CELL;
                if (--BombCount <= 0) {
                    break;
                }
            }
        }
    } else {
        for (int i = R - 1; i >= 0; --i) {
            if (BombCount <= 0) {
                break;
            }
            for (int j = C - 1; j >= 0; --j) {
                if (BombCount <= 0) {
                    break;
                }
                if (is_debug) qDebug() << "2 Matrix[" << i << "][" << j << "], BombCount: " << BombCount;
                if (j < 2 && BombCount < 2) {
                    continue;
                }
                Matrix[i][j] = BOMB_CELL;
                if (--BombCount <= 0) {
                    break;
                }
            }
        }
    }*/

    QString result;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            switch(Matrix[i][j]) {
                case START_CELL:
                    result.append("c");
                    break;
                case BOMB_CELL:
                    result.append("*");
                    break;
                default:
                    result.append(".");
                    break;
            }
        }
        if (i != R - 1) {
            result.append("\n");
        }
    }

    return result;
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
    QStringList sl;

    while (!in.atEnd()) {
        line = in.readLine();
        if (++Idx == 0) {
            if (is_debug) {
                qDebug() << "Input case count " << line;
            }
            continue;
        }

        sl = line.split(" ");
        out << "Case #" << ++CaseNum << ":";// << line;
        endl(out);
        out << getAnswer(sl.at(0).toInt(), sl.at(1).toInt(), sl.at(2).toInt());
        endl(out);
    }
    return 0;
}
