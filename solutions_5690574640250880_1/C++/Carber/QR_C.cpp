#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <assert.h>

using namespace std;

const int maxn = 52;
char g[maxn][maxn];
int R, C, M;

bool isVaild(int x, int y)
{
    return x >= 0 && x < R && y >= 0 && y < C && g[x][y] == '*';
}

int getFreeCount(int x, int y)
{
    int cnt = 0;
    for (int dx = -1; dx <= 1; ++dx)
    {
        for (int dy = -1; dy <= 1; ++dy)
        {
            int tx = x + dx;
            int ty = y + dy;
            if (isVaild(tx, ty))
                ++cnt;
        }
    }
    return cnt;
}

void fillFreePos(int x, int y)
{
    for (int dx = -1; dx <= 1; ++dx)
    {
        for (int dy = -1; dy <= 1; ++dy)
        {
            int tx = x + dx;
            int ty = y + dy;
            if (isVaild(tx, ty))
                g[tx][ty] = '.';
        }
    }
}

void putResult()
{
    g[0][0] = 'c';
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
            putchar(g[i][j]);
        puts("");
    }
}

void Solved()
{
    cin >> R >> C >> M;
    memset(g, '*', sizeof(g));
    M = R * C - M;
    //cout << R << ' ' << C << ' ' << M << endl;
    if (M == 1)
    {
        putResult();
        return;
    }
    int curCnt = getFreeCount(0, 0);
    fillFreePos(0, 0);
    
    
    if (curCnt > M)
    {
        puts("Impossible");
        return ;
    }
    int mr = max(C, R);
    bool cntR = false, cntC = false;
    for (int p = 1; p < mr; ++p)
    {
        if (p < R - 1)
        {
            int cnt = getFreeCount(p, 0);
            if (curCnt + cnt <= M)
            {
                curCnt += cnt;
                fillFreePos(p, 0);
                cntR = true;
            }
            else
                break;
        }
        if (p < C - 1)
        {
            int cnt = getFreeCount(0, p);
            if (curCnt + cnt <= M)
            {
                curCnt += cnt;
                fillFreePos(0, p);
                cntC = true;
            }
            else
                break;
        }
        if (curCnt == M)
            break;
    }

    if (curCnt == M)
    {
        putResult();
        return;
    }

    if (cntR && cntC)
    {
        for (int i = 1; i < R; ++i)
        {
            for (int j = 1; j < C; ++j)
            {
                int cnt = getFreeCount(i, j);
                assert(cnt <= 1);
                curCnt += cnt;
                fillFreePos(i, j);
                if (curCnt == M)
                {
                    putResult();
                    return;
                }
            }
        }
    }
    else
    {
        puts("Impossible");
    }
}

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);

    int nT = 1;
    scanf("%d", &nT);
    for (int nCase = 1; nCase <= nT; ++nCase)
    {
        printf("Case #%d:\n", nCase);
        Solved();
    }

    return 0;
}