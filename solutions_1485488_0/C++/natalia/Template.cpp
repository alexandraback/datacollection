#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define NMAX 105
#define INF 1000000009

int n, m, h;
int d[NMAX][NMAX];
int f[NMAX][NMAX], c[NMAX][NMAX];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && f[x][y] + 50 <= c[x][y];
}

void bfs1(int sx, int sy)
{   
    forn(i, NMAX) forn(j, NMAX) d[i][j] = INF;
    d[sx][sy] = 0;

    queue<int> qx, qy;
    qx.push(sx);
    qy.push(sy);

    while (!qx.empty())
    {
        int ux = qx.front(); qx.pop();
        int uy = qy.front(); qy.pop();

        forn(i, 4)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];
            
            if (valid(vx, vy) && h + 50 <= c[vx][vy] && f[ux][uy] + 50 <= c[vx][vy] && f[vx][vy] + 50 <= c[ux][uy])
            {
                if (d[vx][vy] > 0)
                {
                    d[vx][vy] = 0;
                    qx.push(vx);
                    qy.push(vy);                    
                }
            }
        }
    }
}

bool used[NMAX][NMAX];

void bfs2()
{   
    memset(used, 0, sizeof(used));

    queue<int> qx, qy;
    forn(i, n)
    {
        forn(j, m)
        {
            if (d[i][j] == 0)
            {
                qx.push(i);
                qy.push(j);
            }
        }
    }

    while (!qx.empty())
    {
        int ux = qx.front(); qx.pop();
        int uy = qy.front(); qy.pop();
        used[ux][uy] = false;

        forn(i, 4)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];
            
            if (valid(vx, vy) && f[ux][uy] + 50 <= c[vx][vy] && f[vx][vy] + 50 <= c[ux][uy])
            {
                int cur_h = max(h - d[ux][uy], 0);
                int tmp = 0;

                if (cur_h + 50 > c[vx][vy])
                {
                    tmp += cur_h + 50 - c[vx][vy];
                    cur_h = c[vx][vy] - 50;
                }                

                if (cur_h >= f[ux][uy] + 20)
                {
                    tmp += 10;
                }
                else
                {
                    tmp += 100;
                }

                if (d[vx][vy] > d[ux][uy] + tmp)
                {   
                    d[vx][vy] = d[ux][uy] + tmp;

                    if (!used[vx][vy])
                    {
                        used[vx][vy] = true;
                        qx.push(vx);
                        qy.push(vy);
                    }
                }
            }
        }
    }
}

void solve(int test)
{       
    printf("Case #%d: ", test);

    scanf("%d %d %d", &h, &n, &m);

    forn(i, n) forn(j, m) scanf("%d", &c[i][j]);
    forn(i, n) forn(j, m) scanf("%d", &f[i][j]);

    bfs1(0, 0); 
    bfs2();

    double ans = d[n - 1][m - 1] / 10.0;

    printf("%.1lf\n", ans);
}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc;
    scanf("%d\n", &tc);
    forn(it, tc) solve(it + 1);
    
    return 0;
}