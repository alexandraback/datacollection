#include <QtCore>
#include <stdio.h>
//#include <gmp.h>
#include <string.h>
// (second time ever that I use GMP :p )

static char res[1024 * 16];

static int X, Y;

QByteArray run()
{
    scanf("%d", &X);
    scanf("%d", &Y);
    QHash<QPair<int, int>, QByteArray> accessed, new_one;
    QPair<int, int> pair, target = QPair<int, int>(X, Y);
    accessed[QPair<int, int>(0, 0)] = QByteArray();
    int current = 1;
    char cE = 'E', cW = 'W', cN = 'N', cS = 'S';
    while (true)
    {
        new_one.clear();
        QHashIterator<QPair<int, int>, QByteArray> iter(accessed);
        while (iter.hasNext())
        {
            iter.next();
            pair = iter.key();
            pair.first += current;
            if ((pair.first < (X > 0 ? X : 0) + qAbs(X) + 20) && (!new_one.contains(pair)))
            {
                new_one[pair] = iter.value() + cE;
                if (pair == target) return QByteArray(new_one[pair]);
            }
            pair = iter.key();
            pair.first -= current;
            if ((pair.first > (X < 0 ? X : 0) - qAbs(X) - 20) && (!new_one.contains(pair)))
            {
                new_one[pair] = iter.value() + cW;
                if (pair == target) return QByteArray(new_one[pair]);
            }
            pair = iter.key();
            pair.second += current;
            if ((pair.second < (Y > 0 ? Y : 0) + qAbs(Y) + 20) && (!new_one.contains(pair)))
            {
                new_one[pair] = iter.value() + cN;
                if (pair == target) return QByteArray(new_one[pair]);
            }
            pair = iter.key();
            pair.second -= current;
            if ((pair.second > (Y < 0 ? Y : 0) - qAbs(Y) - 20) && (!new_one.contains(pair)))
            {
                new_one[pair] = iter.value() + cS;
                if (pair == target) return QByteArray(new_one[pair]);
            }
        }
        accessed = QHash<QPair<int, int>, QByteArray>(new_one);
        ++current;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
    {
        QByteArray temp = run();
        temp.append((char) 0);
        printf("Case #%d: %s\n", i, temp.constData());
    }
    return 0;
}
