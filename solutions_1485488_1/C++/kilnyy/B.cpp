#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

int h,n,m;
int f[101][101], c[101][101];
int t[101][101];
int qx[100001],qy[100001],qt,qw;
bool inq[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
const int oo = 100000000;
void init()
{
    memset(inq,0,sizeof(inq));
    scanf("%d%d%d",&h,&n,&m);
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
    {
        t[i][j] = oo;
        scanf("%d",&c[i][j]);
    }
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
    {
        scanf("%d",&f[i][j]);
    }
    t[1][1]=0;
    qt = 0;qw = 0;
}

int calc(int t1, int f1, int c1, int f2, int c2)
{
    if (c2 - f1 < 50 || c2 - f2 < 50 || c1 - f2 < 50) return oo;
    int th = c2 - 50;
    int curh = h - t1;
    int res = t1;
    if (curh > th) res += curh - th;
    if (curh < th) th = curh;
    if (res > 0)
    {
        if (th - f1 >= 20) res += 10;
        else res += 100;
    }
    return res;
}

bool CanMove(int x,int y)
{
    return (x > 0 && y > 0 && x <= n && y <= m);
}

int solve()
{
    init();
    qx[0] = 1;
    qy[0] = 1;
    inq[1][1] = true;
    while (qt <= qw)
    {
        int x = qx[qt];
        int y = qy[qt];
        inq[x][y] = false;
        qt++;
        
        for (int i=0;i<4;i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (!CanMove(tx,ty)) continue;
            int val = calc(t[x][y], f[x][y], c[x][y], f[tx][ty], c[tx][ty]);
            if (val < t[tx][ty])
            {
                t[tx][ty] = val;
                if (!inq[tx][ty])
                {
                    qw++;
                    qx[qw] = tx;
                    qy[qw] = ty;
                    inq[tx][ty] = true;
                }
            }
        }
    }
    return t[n][m];
}

int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int T;
    scanf("%d",&T);
    for (int i=1;i<=T;i++)
    {
        printf("Case #%d: %.1f\n",i,solve() * 0.1);
    }
    return 0;
}
