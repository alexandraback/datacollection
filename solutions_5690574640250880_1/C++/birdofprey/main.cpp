#include <QFile>
#include <QtGlobal>
#include <QTextStream>

#include <iostream>

//#define STDOUT

QTextStream input;

#ifndef STDOUT
    QTextStream output;
#else
    std::ostream &output = std::cout;
#endif

void CaseR1(int C, int M)
{
    for(int i = 0; i < M; ++i) output << '*';
    for(int i = M; i < C - 1; ++i) output << '.';
    output << "c\n";
}

void CaseC1(int R, int M)
{
    for(int i = 0; i < M; ++i) output << "*\n";
    for(int i = M; i < R - 1; ++i) output << ".\n";
    output << "c\n";
}

void CaseDenseMineField(int R, int C)
{
    for(int r = 0; r < R - 1; ++r) {
        for(int c = 0; c < C; ++c)
            output << '*';
        output << '\n';
    }
    for(int c = 0; c < C - 1; ++c)
        output << '*';
    output << "c\n";
}

void CaseR2(int C, int M)
{
    static const int R = 2;
    if((M > R * C - 4) || (M % 2 != 0))
        output << "Impossible\n";
    else {
        for(int c = 0; c < M / 2; ++c) output << '*';
        for(int c = M / 2; c < C; ++c) output << '.';
        output << '\n';
        for(int c = 0; c < M / 2; ++c) output << '*';
        for(int c = M / 2; c < C - 1; ++c) output << '.';
        output << "c\n";
    }
}

void CaseC2(int R, int M)
{
    static const int C = 2;
    if((M > R * C - 4) || (M % 2 != 0))
        output << "Impossible\n";
    else {
        for(int r = 0; r < M / 2; ++r) output << "**\n";
        for(int r = M / 2; r < R - 1; ++r) output << "..\n";
        output << "c.\n";
    }
}

void RegularCase(int R, int C, int M)
{
    int RC = R * C;
    if((M > RC - 8) && (M != RC - 6) && (M != RC - 4)) {
        output << "Impossible\n"; return;
    }
    bool **mines = new bool* [R];
    for(int r = 0; r < R; ++r) {
        mines[r] = new bool [C];
        memset(mines[r], 0, C * sizeof(bool));
    }

    for(int r = 0; (r < R - 2) && (M > 0); ++r) {
        for(int c = 0; (c < C - 2) && (M > 0); ++c) {
            mines[r][c] = true; --M;
        }
    }

    for(int r = 0; (r < R - 3) && (M > 0); ++r) {
        mines[r][C - 2] = true;
        mines[r][C - 1] = true;
        M -= 2;
        if(M < 0) mines[R - 3][C - 3] = false;
    }

    for(int c = 0; (c < C - 3) && (M > 0); ++c) {
        mines[R - 2][c] = true;
        mines[R - 1][c] = true;
        M -= 2;
        if(M < 0) mines[R - 3][C - 3] = false;
    }

    if(M > 0) {
        mines[R - 3][C - 2] = true;
        mines[R - 3][C - 1] = true;
        M -= 2;
    }

    if(M > 0) {
        mines[R - 2][C - 3] = true;
        mines[R - 1][C - 3] = true;
        M -= 2;
    }

    if(M > 0) qFatal("SOMETHING IS WRONG!");

    for(int r = 0; r < R - 1; ++r) {
        for(int c = 0; c < C; ++c)
            output << (mines[r][c] ? '*' : '.');
        output << '\n';
    }
    for(int c = 0; c < C - 1; ++c)
        output << (mines[R - 1][c] ? '*' : '.');
    output << "c\n";

    for(int r = 0; r < R; ++r)
        delete[] mines[r];
    delete[] mines;
}

void SolveCase()
{
    int R, C, M; input >> R >> C >> M; output << "\n";
    if      (R == 1) CaseR1(C, M);
    else if (C == 1) CaseC1(R, M);
    else if (M == R * C - 1) CaseDenseMineField(R, C);
    else if (R == 2) CaseR2(C, M);
    else if (C == 2) CaseC2(R, M);
    else RegularCase(R, C, M);
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
