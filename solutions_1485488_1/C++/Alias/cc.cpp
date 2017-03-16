#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <math.h>
#include <queue>
#include <memory.h>
#include <iostream>
#include <stack>
#include <complex>
#include <list>

using namespace std;
 
void ASS(bool bb)
{
    if (!bb)
    {
        ++*(int*)0;
    }
}
 
#define FOR(i, x) for (int i = 0; i < (int)(x); i++)
#define CL(x) memset(x, 0, sizeof(x))
#define CLX(x, y) memset(x, y, sizeof(x))
 
#pragma comment(linker, "/STACK:106777216")
 
typedef vector<int> vi;

typedef long long LL;

const int N = 128;
const int inf = 1 << 29;

int h, n, m;

struct S
{
    int d;
    int x, y;
    bool operator < (const S& s) const
    {
        return d > s.d;
    }
};


priority_queue<S> q;

int c[N][N];
int f[N][N];
int d[N][N];

bool Ok(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void Add(int x, int y, int dd)
{
    if (d[x][y] > dd)
    {
        d[x][y] = dd;
        S s;
        s.d = dd;
        s.x = x;
        s.y = y;
        q.push(s);
    }
}

bool Can(int c0, int f0, int c1, int f1, int w)
{
    if (c1 - max(f1, w) < 50)
        return 0;
    if (c0 - max(f0, w) < 50)
        return 0;
    int cc = min(c0, c1);
    int ff = max(f0, f1);
    ff = max(ff, w);
    return cc - ff >= 50;
}

void Solve()
{
    cin >> h >> n >> m;
    FOR(i, n)
        FOR(j, m)
        {
            cin >> c[i][j];
        }
    FOR(i, n)
        FOR(j, m)
        {
            cin >> f[i][j];
        }
    FOR(i, n)
        FOR(j, m)
            d[i][j] = inf;
    Add(0, 0, 0);
    while (!q.empty()) {
        const int dd = q.top().d;
        const int x = q.top().x;
        const int y = q.top().y;
        q.pop();
        for (int dx = -1; dx <= 1; dx++)
            for (int dy = -1; dy <= 1; dy++) if ((dx == 0) ^ (dy == 0)) {
                int nx = x + dx;
                int ny = y + dy;
                int HH = h;
                if (Ok(nx, ny) && Can(c[x][y], f[x][y], c[nx][ny], f[nx][ny], HH)) {
                    int nd = dd + 100;
                    if (HH - f[x][y] >= 20)
                        nd = dd + 10;
                    Add(nx, ny, nd);
                }
            }
    }
    FOR(i, n)
        FOR(j, m)
            if (d[i][j] != inf) {
                d[i][j] = inf;
                Add(i, j, 0);
            }
    while (!q.empty()) {
        const int dd = q.top().d;
        const int x = q.top().x;
        const int y = q.top().y;
        q.pop();
        for (int dx = -1; dx <= 1; dx++)
            for (int dy = -1; dy <= 1; dy++) if ((dx == 0) ^ (dy == 0)) {
                int nx = x + dx;
                int ny = y + dy;
                int L = dd - 1;
                int R = 1 << 28;
                while (R - L > 1) {
                    int m = (L + R) / 2;
                    if (Can(c[x][y], f[x][y], c[nx][ny], f[nx][ny], max(0, h - m)))
                        R = m;
                    else
                        L = m;
                }
                int HH = R;
                if (Ok(nx, ny) && Can(c[x][y], f[x][y], c[nx][ny], f[nx][ny], max(0, h - HH))) {
                    int nd = HH + 100;
                    if (h - HH - f[x][y] >= 20)
                        nd = HH + 10;
                    Add(nx, ny, nd);
                }
            }
    }
    int res = d[n - 1][m - 1];
    ASS(res != inf);
    printf(" %0.9lf\n", res / 10.0);
}

int main()
{
    freopen("c:\\gcj\\in.txt", "r", stdin);
    freopen("c:\\gcj\\out.txt", "w", stdout);
    int t;
    cin >> t;
    FOR(i, t)
    {
        printf("Case #%d:", (i + 1));
        Solve();
    }
    return 0;
}