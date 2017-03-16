/*
ID: CUGB-wwj
PROG:
LANG: C++
*/
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#define INF 2000000000
#define MAXN 1111
#define MAXM 1005
#define L(x) x<<1
#define R(x) x<<1|1
#define eps 1e-4
using namespace std;
int bom;
int n, m;
bool vis[55][55];
int flag;
int xx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int yy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool inside(int x, int y)
{
    if(x < 1 || y < 1 || x > n || y > m) return false;
    return true;
}
int check(int tx, int ty, bool v[55][55])
{
    int cnt = 0;
    for(int i = 0; i < 8; i++)
    {
        int x = tx + xx[i];
        int y = ty + yy[i];
        if(inside(x, y) && !v[x][y]) cnt++;
    }
    return cnt;
}
void gao1(int tx, int ty, bool v[55][55], int g[])
{
    for(int i = 0; i < 8; i++)
    {
        int x = tx + xx[i];
        int y = ty + yy[i];
        if(inside(x, y) && !v[x][y])
        {
            g[i] = 1;
            v[x][y] = 1;
        }
    }
}
void gao2(int tx, int ty, bool v[55][55], int g[])
{
    for(int i = 0; i < 8; i++)
    {
        int x = tx + xx[i];
        int y = ty + yy[i];
        if(inside(x, y) &&g[i] == 1)
        {
            v[x][y] = 0;
        }
    }
}
void dfs(int r, int c, bool v[55][55], int num)
{
    if(flag) return;
    if(num > bom) return ;
    if(num == bom)
    {
        flag = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(i == 1 && j == 1) printf("c");
                else if(v[i][j]) printf(".");
                else printf("*");
            }
            printf("\n");
        }
        return;
    }
    bool tt[55][55];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            tt[i][j] = v[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(!tt[i][j]) continue;
            int ad = check(i, j, tt);
            if(ad)
            {
                int g[9];
                memset(g, 0, sizeof(g));
                gao1(i, j, tt, g);
                dfs(i, j, tt, num + ad);
                gao2(i, j, tt, g);
            }
        }
}
int main()
{
    freopen("C:/C-small-attempt0.in", "r", stdin) ;
    freopen("C:/c.out" , "w" , stdout) ;
    int T, cas = 0;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d%d%d", &n, &m, &bom);
        bom = n * m - bom;
        printf("Case #%d:\n", ++cas);
        if(bom == 0)
        {
            printf("Impossible\n");
            continue;
        }
        flag = 0;
        memset(vis, 0, sizeof(vis));
        vis[1][1] = 1;
        dfs(1, 1, vis, 1);
        if(!flag)  printf("Impossible\n");
    }
    return 0 ;
}


