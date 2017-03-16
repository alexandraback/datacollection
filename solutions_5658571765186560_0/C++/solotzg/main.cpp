#include <cstdio>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cstring>
#include <array>
#include <queue>
#include <set>
#include <map>
using namespace std;
const int MAXN = 50;
int vis[MAXN][MAXN];
int r, c, N;
inline int isoverborder(int x, int y, int xx = 0)
{
    return x<xx || x >= r || y < 0 || y >= c;
}
const int dir[4][2] = {0,1,0,-1,-1,0,1,0};
int bx;
int da[MAXN][2], nd;
int mvis[MAXN][MAXN];
int bfs(int x, int y)
{
    static int qq[500][2];
    int head = 0, tail = 0;
    qq[tail][0] = x;
    qq[tail][1] = y;
    ++tail;
    int cnt = 0;
    while (head < tail)
    {
        int xx = qq[head][0];
        int yy = qq[head][1];
        ++head;
        if (mvis[xx][yy]) continue;
        mvis[xx][yy] = 1;
        ++cnt;
        for (int i = 0; i< 4; ++i)
        {
            int a = xx+dir[i][0], b = yy+dir[i][1];
            if (isoverborder(a,b) || mvis[a][b]) continue;
            qq[tail][0] = a;
            qq[tail++][1] = b;
        }
    }
    return cnt;
}
int msearch()
{
    int cnt = 0;
    for (int i = 0; i< r; ++i)
    {
        for (int j = 0; j< c; ++j)
        {
            if (mvis[i][j]) continue;
            if (bfs(i, j) % N != 0)
                return 0;
        }
    }
    return 1;
}
void zhuan(int nd)
{
    for (int i = 0, j; i< nd; ++i)
    {
        j = da[i][0];
        da[i][0] = -da[i][1];
        da[i][1] = j;
    }
}
int caonima[MAXN][2];
int dfs1(int nd)
{
    if (nd == N)
    {
        memcpy(caonima, da, sizeof da);
        for (int dg = 0; dg < 4; ++dg)
        {
            zhuan(nd);
            int mxx=da[0][0], mnx=da[0][0], mxy=da[0][1], mny=da[0][1];
            for (int i = 1; i< N; ++i)
            {
                mxx = max(mxx, da[i][0]);
                mnx = min(mnx, da[i][0]);
                mxy = max(mxy, da[i][1]);
                mny = min(mny, da[i][1]);
            }
            for (int i = 0; i< r; ++i)
            {
                for (int j = 0; j< c; ++j)
                {
                    // 找起点
                    if ((mxx + i) < r &&(mnx + i) >= 0 && (mxy+j) < c && (mny+j)>=0)
                    {
                        memset(mvis, 0, sizeof mvis);
                        for (int u = 0; u< N; ++u)
                        {
                            mvis[i+da[u][0]][j+da[u][1]] = 1;
                        }
                        // 剩余的联通区域内未覆盖的数量都是N的倍数
                        if (msearch())
                        {
                            memcpy(da, caonima, sizeof da);
                            return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }
    for (int i = 0; i< nd; ++i)
    {
        int x = da[i][0], y = da[i][1];
        for (int j = 0; j< 4; ++j)
        {
            int xx = x+dir[j][0], yy = y+dir[j][1];
            if (xx>=0 && !vis[xx+20][yy+20])
            {
                vis[xx+20][20+yy] = 1;
                da[nd][0] = xx;
                da[nd][1] = yy;
                if (dfs1(nd+1))
                    return 1;
                vis[xx+20][20+yy] = 0;
            }
        }
    }
    return 0;
}
int solve()
{
    scanf("%d%d%d", &N, &r, &c);
    //printf("(%d,%d,%d) ", N, r, c);
    if (r*c % N!=0) return 1;
    if (N == 1) return 0;
    if (N >= 7) return 1;
    da[0][0] = da[0][1] = 0;
    memset(vis, 0, sizeof vis);
    vis[20][20] = 1;
    return dfs1(1);
}
int main()
{
    freopen("/home/solotzg/下载/D-small-attempt3.in", "r",stdin);
    //freopen("in.txt", "r",stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int _ = 1; _<= t; ++_)
    {
        printf("Case #%d: ", _);
        if (solve())
            puts("RICHARD");
        else
            puts("GABRIEL");
    }
    return 0;
}
