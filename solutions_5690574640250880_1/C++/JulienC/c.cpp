#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <tuple>

using namespace std;

char grid[50][50];
map<tuple<int,int,int>, bool> cache;

bool solve(int R, int C, int M, int level);

void verifyGrid(int R, int C, int M)
{
    int mineCounter = 0;
    assert(grid[0][0] == 'c');
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (grid[i][j] == '*')
            {
                mineCounter++;
            }
        }
    }
    assert(mineCounter == M);
}

void printGrid(int R, int C)
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

void initGrid(int R, int C)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            grid[i][j] = '.';
        }
    }
    grid[0][0] = 'c';
}

bool isInCache(int R, int C, int M)
{
    auto tup = make_tuple(R, C, M);
    return cache.find(tup) != cache.end();
}

void addToCache(int R, int C, int M, bool val)
{
    auto tup = make_tuple(R, C, M);
    if (cache.find(tup) != cache.end())
    {
        assert(cache[tup] == val);
    }
    else
    {
        cache[tup] = val;
    }
}

bool getCache(int R, int C, int M)
{
    auto tup = make_tuple(R, C, M);
    assert(cache.find(tup) != cache.end());
    return cache.at(tup);
}

bool reduceRow(int R, int C, int M, int level)
{
    if (M < C)
    {
        return false;
    }
    if (!solve(R-1, C, M-C, level+1))
    {
        return false;
    }
    for (int j = 0; j < C; j++)
    {
        grid[R-1][j] = '*';
    }
    return true;
}

bool reduceColumn(int R, int C, int M, int level)
{
    if (M < R)
    {
        return false;
    }
    if (!solve(R, C-1, M-R, level+1))
    {
        return false;
    }
    for (int i = 0; i < R; i++)
    {
        grid[i][C-1] = '*';
    }
    return true;
}

bool solve(int R, int C, int M, int level)
{
    assert(R > 0);
    assert(C > 0);
    if (isInCache(R, C, M) && !getCache(R, C, M))
    {
        return false;
    }

    if (R == 1 || C == 1)
    {
        if (level > 0)
        {
            return false;
        }
        if (R == 1)
        {
            for (int j = C-M; j < C; j++)
            {
                grid[0][j] = '*';
            }
            addToCache(R, C, M, true);
            return true;
        }
        if (C == 1)
        {
            for (int i = R-M; i < R; i++)
            {
                grid[i][0] = '*';
            }
            addToCache(R, C, M, true);
            return true;
        }
        assert(false); // should never happen
        return false;
    }
    assert(R > 1);
    assert(C > 1);

    if (M == 0)
    {
        addToCache(R, C, M, true);
        return true;
    }

    if (M == R*C - 1)
    {
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
        addToCache(R, C, M, true);
        return true;
    }
    if (M > R*C-4)
    {
        addToCache(R, C, M, false);
        return false;
    }
    if ((R == 2 || C == 2) && (M&1))
    {
        addToCache(R, C, M, false);
        return false;
    }
    if (R == 2)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = C-M/2; j < C; j++)
            {
                grid[i][j] = '*';
            }
        }
        addToCache(R, C, M, true);
        return true;
    }
    if (C == 2)
    {
        for (int i = R-M/2; i < R; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                grid[i][j] = '*';
            }
        }
        addToCache(R, C, M, true);
        return true;
    }

    assert(R > 2);
    assert(C > 2);
    if (M <= R-2)
    {
        for (int i = R-M; i < R; i++)
        {
            grid[i][C-1] = '*';
        }
        addToCache(R, C, M, true);
        return true;
    }
    if (M <= C-2)
    {
        for (int j = C-M; j < C; j++)
        {
            grid[R-1][j] = '*';
        }
        addToCache(R, C, M, true);
        return true;
    }

    if (M == R-1 && C > 3)
    {
        for (int i = 2; i < R; i++)
        {
            grid[i][C-1] = '*';
        }
        grid[R-1][C-2] = '*';
        addToCache(R, C, M, true);
        return true;
    }
    if (M == C-1 && R > 3)
    {
        for (int j = 2; j < C; j++)
        {
            grid[R-1][j] = '*';
        }
        grid[R-2][C-1] = '*';
        addToCache(R, C, M, true);
        return true;
    }

    // heuristic: go towards a square grid
    if (R < C)
    {
        if (reduceColumn(R, C, M, level))
        {
            addToCache(R, C, M, true);
            return true;
        }
        if (reduceRow(R, C, M, level))
        {
            addToCache(R, C, M, true);
            return true;
        }
    }
    else
    {
        if (reduceRow(R, C, M, level))
        {
            addToCache(R, C, M, true);
            return true;
        }
        if (reduceColumn(R, C, M, level))
        {
            addToCache(R, C, M, true);
            return true;
        }
    }

    addToCache(R, C, M, false);
    return false;
}

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ":" << endl;
        int R, C, M;
        cin >> R >> C >> M;

        initGrid(R, C);
        if (solve(R, C, M, 0))
        {
            verifyGrid(R, C, M);
            printGrid(R, C);
        }
        else
        {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}

