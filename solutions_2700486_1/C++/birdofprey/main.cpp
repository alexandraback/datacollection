#include <iostream>
#include <QtGlobal>
using namespace std;

#include <QFile>
#include <QTextStream>

QTextStream input, output;

qint64 Sk(int K)
{
    if(K < 0) return 0;
    return K + 1 + 2 * K * (K + 1);
}

qint64 count(qint64 n, qint64 N)
{
    if(N < n) return 0;
    if(n == 0) return pow(2, qreal(N));
    return count(n, N - 1) + count(n - 1, N - 1);
}

qreal prob(qint64 n, qint64 N)
{
    qint64 test = count(n, N);
    return 1.0 * test / pow(2, qreal(N));
}

void SolveCase()
{
    qint64 N, X, Y;
    input >> N >> X >> Y;
    X = qAbs(X);
    qint64 icur = (X + Y) / 2;
    qreal res = 0.0;
    if      (N <= Sk(icur - 1)) res = 0.0;
    else if (N >= Sk(icur))     res = 1.0;
    else
    {
        qint64 N_top = N - Sk(icur - 1);
        qint64 N_min = qMax(qint64(0), N_top - X - Y);
        qint64 N_max = qMin(X + Y, N_top);

        if      (Y + 1 <= N_min) res = 1.0;
        else if (Y + 1  > N_max) res = 0.0;
        else
        {
            //res = pow(2.0, qreal(N_min - Y - 1));
            res = prob(Y + 1, N_top);
            //res = (1.0 * N_max - Y) / (N_top - 2 * N_min + 1);
        }
    }
    output << res << endl;
}

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    QFile infile("input.txt"), outfile("output.txt");
    infile.open(QIODevice::ReadOnly);
    outfile.open(QIODevice::WriteOnly);
    input.setDevice(&infile);
    output.setDevice(&outfile);

    uint T; input >> T;
    for(uint t = 1; t <= T; ++t)
    {
        output << "Case #" << t << ": ";
        SolveCase();
    }

    return 0;
}
