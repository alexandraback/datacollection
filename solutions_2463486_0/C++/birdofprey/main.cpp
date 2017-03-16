#include <cmath>
#include <cstring>
#include <iostream>
#include <QtGlobal>
using namespace std;

#include <QFile>
#include <QVector>
#include <QTextStream>

QTextStream input, output;

QVector<quint64> data;

void ConvertToDigitsArray(quint64 x, char array[])
{
    uint res = 0;
    while(x != 0)
    {
        array[res++] = '0' + x % 10;
        x /= 10;
    }
    array[res] = '\0';
}

quint64 ConvertToNumber(char digits[])
{
    quint64 res = 0; int i = 0;
    while(digits[i] != '\0')
        res = 10 * res + (digits[i++] - '0');
    return res;
}

bool IsPalindrome(char digits[])
{
    int size = strlen(digits);
    for(int i = 0, mid = (size - 1) / 2; i <= mid; ++i)
        if(digits[i] != digits[size - i - 1]) return false;
    return true;
}

void Square(char src[], char res[])
{
    quint64 tmp = ConvertToNumber(src);
    ConvertToDigitsArray(tmp * tmp, res);
}

/* Assumes that p is palindrome! */
void NextPalindrome(char p[])
{
    int size = strlen(p);
    int a = (size - 1) / 2, b = size - a - 1;
    do
    {
        if(p[a] < '9')
        {
            ++p[a];
            if(b != a) ++p[b];
            return;
        }
        else
        {
            p[a--] = '0';
            p[b++] = '0';
        }
    } while(a >= 0);
    memset(p, '0', size + 1);
    p[0] = '1';
    p[size] = '1';
    p[size + 1] = '\0';
}

void GenerateData(quint64 max)
{
    max = sqrt(double(max));
    char p[102] = "1", square[102];
    do
    {
        Square(p, square);
        if(IsPalindrome(square))
        {
            cout << square << endl;
            data.append(ConvertToNumber(square));
        }
        NextPalindrome(p);
    } while(ConvertToNumber(p) < max);
}

void SolveCase()
{
    quint64 A, B;
    input >> A >> B;
    int res = 0;
    QVector<quint64>::ConstIterator i = data.constBegin(), end = data.constEnd();
    while((i != end) && (*i < A)) ++i;
    while((i != end) && (*i <=  B))
    {
        ++res;
        ++i;
    }
    output << res << endl;
}

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    GenerateData(pow(10.0, 14.0));

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
