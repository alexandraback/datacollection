#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>

using namespace std;

char grid[50][50];

int realM;

void verifyGrid(int R, int C)
{
    int mineCounter = 0;
    assert(grid[0][0] == 'c');
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            assert(grid[i][j] != '#');
            if (grid[i][j] == '*')
            {
                mineCounter++;
            }
        }
    }
    assert(mineCounter == realM);
}

void printGrid(int R, int C, bool transpose)
{
    verifyGrid(R, C);
    if (transpose)
    {
        for (int j = 0; j < C; j++)
        {
            for (int i = 0; i < R; i++)
            {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
}

void initGrid(int R, int C)
{
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            grid[i][j] = '#';
        }
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            grid[i][j] = '.';
        }
    }
    grid[0][0] = 'c';
}

bool solve(int R, int C, int M)
{
    if (M > R*C - 4)
    {
        cerr << "too many mines, can't even clear 4x4" << endl;
        return false;
    }

    int freeRows = R; 
    while (freeRows > 2 && M >= C)
    {
        for (int j = 0; j < C; j++)
        {
            grid[freeRows-1][j] = '*';
        }
        M -= C;
        freeRows--;

        if (M % freeRows == 0 && C - (M / freeRows) >= 2)
        {
            cerr << "ok, can fit remaining mines vertically" << endl;
            for (int i = 0; i < freeRows; i++)
            {
                for (int j = C-(M/freeRows); j < C; j++)
                {
                    grid[i][j] = '*';
                }
            }
            return true;
        }

        if (freeRows > 2 && M % freeRows == 1 && C - (M / freeRows) > 2)
        {
            cerr << "ok, that 5 5 14 case" << endl;
            for (int i = 0; i < freeRows; i++)
            {
                for (int j = C-(M/freeRows); j < C; j++)
                {
                    grid[i][j] = '*';
                }
            }
            grid[freeRows-1][C-(M/freeRows)-1] = '*';
            return true;
        }
    }

    if (M == 0)
    {
        cerr << "ok, all mines fit exactly on rows" << endl;
        return true;
    }

    if (freeRows == 2)
    {
        if (M & 1)
        {
            cerr << "2 free rows, odd number of mines remaining" << endl;
            return false;
        }
        cerr << "ok, 2 free rows, even number of mines remaining" << endl;
        int j = C-1;
        while (M)
        {
            grid[0][j] = '*';
            grid[1][j] = '*';
            M -= 2;
            j--;
        }
        return true;
    }

    if (M <= C-2)
    {
        cerr << "ok, more than 2 free rows, just a few mines remaining" << endl;
        for (int j = C-M; j < C; j++)
        {
            grid[freeRows-1][j] = '*';
        }
        return true;
    }

    assert(M == C-1);

    if (freeRows > 3 && C > 2)
    {
        cerr << "ok, more than 3 rows, can put an extra mine on top" << endl;
        for (int j = 2; j < C; j++)
        {
            grid[freeRows-1][j] = '*';
        }
        grid[freeRows-2][C-1] = '*';
        return true;
    }

    cerr << "don't know what to do anymore" << endl;
    return false;
}

bool solveTrivialCases(int R, int C, int M)
{
    if (M == 0)
    {
        cerr << "trivial case: no mines!" << endl;
        return true;
    }
    if (M == R*C - 1)
    {
        cerr << "trivial case: grid is full except (0,0)" << endl;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (i == 0 && j == 0)
                {
                    continue;
                }
                grid[i][j] = '*';
            }
        }
        return true;
    }
    if (R == 1)
    {
        cerr << "trivial case: only one row" << endl;
        for (int j = C-M; j < C; j++)
        {
            grid[0][j] = '*';
        }
        return true;
    }
    if (C == 1)
    {
        cerr << "trivial case: only one column" << endl;
        for (int i = R-M; i < R; i++)
        {
            grid[i][0] = '*';
        }
        return true;
    }
    return false;
}


int main()
{
    int T;
    cin >> T;
    ofstream impossible("impossible.in");
    for (int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ":" << endl;
        int R, C, M;
        cin >> R >> C >> M;
        realM = M;
        initGrid(R, C);
        if (solveTrivialCases(R, C, M))
        {
            printGrid(R, C, false);
            continue;
        }
        if (solve(R, C, M))
        {
            printGrid(R, C, false);
            continue;
        }
        initGrid(C, R);
        if (solve(C, R, M))
        {
            printGrid(C, R, true);
            continue;
        }
        cout << "Impossible" << endl;
        impossible << R << " " << C << " " << M << endl;
    }
    impossible.close();
    return 0;
}

