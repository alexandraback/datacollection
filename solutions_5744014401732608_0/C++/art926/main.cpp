#include <QFile>
#include <QTextStream>
#include <QVector>

//Artem Klimov's solution
//soved using Qt Framework


QFile inFile("C:/CodeJam2016/Round1C/B/B-small-attempt1.in");
QFile outFile("C:/CodeJam2016/Round1C/B/output.txt");

int main(int argc, char *argv[])
{
    inFile.open(QFile::ReadOnly);
    outFile.open(QFile::WriteOnly);
    QTextStream inData(&inFile);
    QTextStream outData(&outFile);

    int T;
    inData >> T;
    char matrix[50][50];
    qint64 progression[50];

    progression[0] = 1;
    progression[1] = 1;

    for(int i=2; i<50; i++)
    {
        progression[i] = 1;
        for(int j=(i-1); j>=1; j--) progression[i] += progression[j];
    }

    for(int t=0; t<T; t++)
    {
        qint64 B, M;
        inData >> B;
        inData >> M;

        int maxPosible = 1;
        for(int i=1; i<=(B-2); i++) maxPosible += progression[i];

        outData << QString("Case #%1: ").arg(t+1);
        if(M>maxPosible)
        {
            outData << "IMPOSSIBLE\r\n";
            continue;
        }

        outData << "POSSIBLE\r\n";

        for(int i=0; i<B; i++)
        {
            for(int j=0; j<B; j++)  matrix[i][j] = 0;
        }

        for(int i=1; i<B; i++) matrix[0][i] = 1;
        for(int i=B-2; i>=1; i--)
        {
            matrix[i][B-1] = 1;
            for(int j=i-1; j>=1; j--) matrix[i][j] = 1;
        }

        for(int i=B-2; i>=1; i--)
        {
            qint64 tPower = progression[i];
            if(M>=tPower) M -= tPower;
            else matrix[0][i] = 0; //remove connection
        }

        if(M==0) matrix[0][B-1] = 0;

        for(int i=0; i<B; i++)
        {
            for(int j=0; j<B; j++)  outData << QString("%1").arg((int)matrix[i][j]);
            outData << "\r\n";
        }
    }
}
