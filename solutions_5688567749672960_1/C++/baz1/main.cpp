#include <QtCore>
#include <stdio.h>

static quint64 pow10Array[15] = {1L, 10L, 100L, 1000L, 10000L, 100000L, 1000000L, 10000000L, 100000000L, 1000000000L, 10000000000L, 100000000000L, 1000000000000L, 10000000000000L, 100000000000000L};

quint64 inv(quint64 n)
{
    quint64 result = 0;
    while (n)
    {
        result *= 10;
        result += (n % 10);
        n /= 10;
    }
    return result;
}

QString computeCase(QTextStream &in)
{
    quint64 n, result = 0, digits = 0, p, minv;
    in >> n;
    while (pow10Array[digits] <= n)
        ++digits;
    while (n)
    {
        if (n % 10 == 0)
        {
            --n;
            ++result;
            if (pow10Array[digits - 1] > n)
                --digits;
            continue;
        }
        if (n < 10)
        {
            result += n;
            break;
        }
        p = pow10Array[(digits + 1) >> 1];
        minv = inv(n/p);
        result += (n % p) + minv;
        if (minv == 1)
            --result;
        n = pow10Array[--digits];
    }
    return QString::number(result);
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
