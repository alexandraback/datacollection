#include <QVector>
#include <QTextStream>

typedef QVector<double> prob;

double solve(int A, int B, prob& P)
{
    double minmean = B + 2;

    double curp = 1;
    for(int i=0;/*i<A*/;++i)
    {
        int backkey = A - i;
        int leftkey = B - i;
        double curmean = (backkey + leftkey + 1) * curp + (1-curp)*(backkey + leftkey + 1 + B + 1);

        if(curmean < minmean)
        {
            minmean = curmean;
        }

        if(i == A)
        {
            break;
        }

        curp *= P[i];
    }
    return minmean;
}

int main(int argc, char *argv[])
{
    QTextStream ins(stdin);
    QTextStream out(stdout);

    int T = QString(ins.readLine()).toInt();
    for (int i = 0; i < T; ++i)
    {
        int A, B;
        ins >> A >> B;
        prob P;
        for(int j=0;j<A;++j)
        {
            double p;
            ins >> p;
            P.push_back(p);
        }

        out << QString("Case #%1: ").arg(QString::number(i + 1)) << QString("%1").arg(solve(A, B, P),-8,'f',6) << endl;
    }

    return 0;
}
