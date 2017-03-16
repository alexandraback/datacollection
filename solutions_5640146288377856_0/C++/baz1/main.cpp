#include <QtCore>
#include <stdio.h>

QString computeCase(QTextStream &in)
{
    int R, C, W, result = 0;
    in >> R >> C >> W;
    result = R * (C / W) + W;
    if (C % W == 0)
        --result;
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
