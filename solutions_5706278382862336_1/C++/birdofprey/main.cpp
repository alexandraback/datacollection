#include <QFile>
#include <QtGlobal>
#include <QTextStream>
#include <cmath>

#include <iostream>

/* Switch between console and file output modes. */
//#define STDOUT

QTextStream input;

#ifndef STDOUT
    QTextStream output;
#else
    std::ostream &output = std::cout;
#endif

void SolveCase()
{
    static const qint64 magic = pow(2, 40); char c;
    double P, Q; input >> P >> c >> Q;
    if(fmod(P * magic,  Q) != 0) output << "impossible\n";
    else {
        double n = P * magic / Q;
        int res = ceil(40 - log(n) / log(2));
        output << res << '\n';
    }
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
#   endif

    uint T; input >> T;
    for(uint t = 1; t <= T; ++t)
    {
        output << "Case #" << t << ": ";
        SolveCase();
    }

    return 0;
}
