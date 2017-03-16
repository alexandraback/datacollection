#include <QtCore>
#include <stdio.h>

long double p[26];
long double lp[101];
int restart_at[101][26];

struct Inst
{
    long double proba;
    QList<long double> started;
};
/*
template <typename T> QDebug &operator<<(QDebug &dbg, QList<T> lst)
{
    dbg << "List:";
    for (int i = lst.length(); --i >= 0;)
        dbg << "  " << lst.at(i);
    return dbg << "EndList.";
}
*/
QString computeCase(QTextStream &in)
{
    int K, L, S;
    in >> K >> L >> S;
    QString keyboard, target;
    in >> keyboard;
    in >> target;
    if ((keyboard.length() != K) || (target.length() != L))
    {
        qDebug() << "Pb1";
        return QString();
    }
    for (int i = 25; i >= 0; --i)
        p[i] = 0;
    for (int i = K; --i >= 0;)
        p[keyboard.at(i).toLatin1() - 'A'] += 1. / K;
    for (int i = L; --i >= 0;)
    {
        lp[i] = p[target.at(i).toLatin1() - 'A'];
        if (lp[i] == 0)
            return "0.0";
    }
    int ending = target.at(L - 1).toLatin1() - 'A';
    for (int j = 25; j >= 0; --j)
    {
        if (p[j] != 0)
        {
            QString str = target + QChar('A' + j);
            for (int i = L; --i >= 0;)
            {
                int tmp = i + 1;
                while (!target.startsWith(str.right(tmp)))
                    --tmp;
                restart_at[i][j] = tmp;
            }
        }
    }
    int rep = L - 1;
    while (!target.endsWith(target.left(rep)))
        --rep;
    int nbananas = 1 + (S - L) / (L - rep);
    QList<long double> nullP;
    nullP.reserve(L);
    for (int i = L; --i >= 0;)
        nullP.append(0);
    Inst firstInst;
    firstInst.proba = 1.;
    firstInst.started = nullP;
    firstInst.started.first() = 1.;
    QList< QList<Inst> > result;
    result.append(QList<Inst>());
    result.first().append(firstInst);
    while (result.length() <= S)
    {
        QList<Inst> to_add;
        int score = 0;
        while (true)
        {
            Inst current;
            current.proba = 0.;
            current.started = nullP;
            if (score)
            {
                long double tmp;
                Inst do_one = result.last().at(score - 1);
                tmp = lp[L - 1] * do_one.started.last();
                current.started[rep] += tmp;
                current.proba += tmp;
            }
            if (result.last().length() > score)
            {
                long double tmp;
                Inst do_zero = result.last().at(score);
                for (int i = L; --i >= 0;)
                {
                    for (int j = 25; j >= 0; --j)
                    {
                        if ((i == L - 1) && (ending == j))
                            continue;
                        if (p[j] == 0)
                            continue;
                        tmp = p[j] * do_zero.started.at(i);
                        current.started[restart_at[i][j]] += tmp;
                        current.proba += tmp;
                    }
                }
            }
            if ((current.proba > 0) || (score < result.last().length()))
            {
                to_add.append(current);
                if (score >= result.last().length())
                    break;
                ++score;
            } else {
                break;
            }
        }
        result.append(to_add);
    }
    long double expect = 0.;
    for (int i = result.at(S).length(); --i >= 0;)
        expect += i * result.at(S).at(i).proba;
    return QString::number((double) (nbananas - expect), 'g', 8);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    if (argc < 2)
    {
        fprintf(stderr, "Error: Missing argument.\n");
        return 1;
    }
    QFile inputFile(argv[1]);
    if (!inputFile.open(QIODevice::ReadOnly))
    {
        fprintf(stderr, "Error: Could not open input file.\n");
        return 1;
    }
    QFile outputFile(QString(argv[1]) + ".out");
    if (!outputFile.open(QIODevice::WriteOnly))
    {
        fprintf(stderr, "Error: Could not open output file.\n");
        inputFile.close();
        return 1;
    }
    int T, i = 0;
    QTextStream input(&inputFile);
    input >> T;
    while (++i <= T)
    {
        QString result = computeCase(input);
        outputFile.write(QString("Case #%1: %2\n").arg(i).arg(result).toUtf8());
    }
    outputFile.close();
    inputFile.close();
    printf("Done.\n");
    return 0;
}
