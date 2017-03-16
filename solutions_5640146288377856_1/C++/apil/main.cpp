#include <QVector>
#include <QTextStream>

int Solve(int R, int C, int W)
{
    int start = R * (C / W);
    return start + W + ((W == C || W == 1 || C % W == 0) ? -1 : 0);
}

int main(int argc, char *argv[])
{
    QTextStream ins(stdin);
    QTextStream out(stdout);

    int T = QString(ins.readLine()).toInt();
    for (int i = 0; i < T; ++i)
    {
        int R, C, W;
        ins >> R >> C >> W;
        //out << QString("Case #%1: ").arg(QString::number(i + 1)) << Solve(R, C, W) << QString(" %1 %2 %3").arg(R).arg(C).arg(W) << endl;
        out << QString("Case #%1: ").arg(QString::number(i + 1)) << Solve(R, C, W) << endl;
    }

    return 0;
}
