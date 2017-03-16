#include <QFile>
#include <QtGlobal>
#include <QTextStream>

#include <QDebug>

#include <iostream>

// #define STDOUT

QTextStream input;

#ifndef STDOUT
    QTextStream output;
#else
    std::ostream &output = std::cout;
#endif

void SolveCase()
{
    double C, F, X; input >> C >> F >> X;
    double rate = 2.0, time = 0.0, result = X / rate;

    /* Let's buy a farm */
    for(;;) {
        time += C / rate;
        if(time > result) break;
        rate += F;
        double alt_result = time + X / rate;
        if(alt_result < result) result = alt_result;
        else break;
    }

    output << result << '\n';
}

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    QFile infile("input.txt");
    infile.open(QIODevice::ReadOnly);
    input.setDevice(&infile);

#   ifndef STDOUT
        QFile outfile("output.txt");
        outfile.open(QIODevice::WriteOnly);
        output.setDevice(&outfile);
        output.setRealNumberPrecision(10);
#   endif

    uint T; input >> T;
    for(uint t = 1; t <= T; ++t)
    {
        output << "Case #" << t << ": ";
        SolveCase();
    }

    return 0;
}
