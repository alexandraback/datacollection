#include <iostream>
#include <QtGlobal>
using namespace std;

#include <QFile>
#include <QTextStream>

QTextStream input, output;

int MaxAtRow(int **a, int row, int M)
{
    int res = -1;
    for(int i = 0; i < M; ++i)
        if(a[row][i] > res) res = a[row][i];
    return res;
}

int MaxAtCol(int **a, int N, int col)
{
    int res = -1;
    for(int i = 0; i < N; ++i)
        if(a[i][col] > res) res = a[i][col];
    return res;
}

void SolveCase()
{
    int N, M; input >> N >> M;
    bool **cut = new bool* [N];
    int **h = new int* [N];
    for(int i = 0; i < N; ++i)
    {
        cut[i] = new bool [M];
        h[i] = new int [M];
        for(int j = 0; j < M; ++j)
        {
            cut[i][j] = false;
            input >> h[i][j];
        }
    }

    /* Cutting rows */
    for(int row = 0; row < N; ++row)
    {
        int cut_height = MaxAtRow(h, row, M);
        for(int col = 0; col < M; ++col)
            if(h[row][col] == cut_height)
                cut[row][col] = true;
    }

    /* Cutting cols */
    for(int col = 0; col < M; ++col)
    {
        int cut_height = MaxAtCol(h, N, col);
        for(int row = 0; row < N; ++row)
            if(h[row][col] == cut_height)
                cut[row][col] = true;
    }

    /* Check if everything is cut */
    bool success = true;
    for(int row = 0; success && (row < N); ++row)
    {
        for(int col = 0; success && (col < M); ++col)
        {
            if(!cut[row][col])
            {
                success = false;
                output << "NO" << endl;
            }
        }
    }
    if(success) output << "YES" << endl;

    for(int i = 0; i < N; ++i)
    {
        delete[] cut[i];
        delete[] h[i];
    }
    delete[] cut;
    delete[] h;
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
