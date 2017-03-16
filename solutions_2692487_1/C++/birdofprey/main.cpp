#include <iostream>
#include <QtGlobal>
using namespace std;

#include <QFile>
#include <QTextStream>

QTextStream input, output;

inline void swap(qint64 *a, qint64 *b) { qint64 tmp = *a; *a = *b; *b = tmp; }

qint64* partition(qint64 *left, qint64 *right)
{
    swap(left + (right - left) / 2, right);
    for(qint64 *i = left; i != right; ++i)
        if(*i < *right) swap(i, left++);
    swap(left, right);
    return left;
}

void quicksort(qint64 array[], int size)
{
    if(size <= 1) return;
    qint64 *pivot = partition(array, array + size - 1);
    quicksort(array, pivot - array);
    quicksort(pivot + 1, size - (pivot - array) - 1);
}

void SolveCase()
{
    int N;
    qint64 A, *size;
    input >> A >> N;
    size = new qint64[N];
    for(int n = 0; n < N; ++n)
        input >> size[n];
    quicksort(size, N);

    if(A == 1)
    {
        output << N << endl;
    }
    else
    {
        int i = 0;
        while((i < N) && (A > size[i])) A += size[i++];

        int res = N - i, added = 0;
        while(i < N)
        {
            ++added;
            A += A - 1;
            while((i < N) && (A > size[i])) A += size[i++];

            int newres = added + N - i;
            if(newres < res) res = newres;
        }
        output << res << endl;
    }

    delete[] size;
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
