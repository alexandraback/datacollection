#include <stdio.h>
#include <iostream>
using namespace std;

#define MAXN (100+10)
#define MAXR (MAXN*MAXN)
#define oo (100000000)
#define xx (1e-6)

const int fx[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int f[MAXN][MAXN], c[MAXN][MAXN];
int r,h,n,m,t,l[MAXR][2];
double g[MAXN][MAXN];
bool fl[MAXN][MAXN];

bool ifenter(int x,int y,int x1,int y1,double h)
{
     if (f[x][y] <= c[x1][y1]-50 && f[x1][y1] <= c[x1][y1]-50
            && f[x1][y1] <= c[x][y]-50 && h <= c[x1][y1]-50) return true;
        else return false;
}

double enter(int x,int y,int x1,int y1,double h)
{
    if (f[x][y] <= c[x1][y1]-50 && f[x1][y1] <= c[x1][y1]-50
            && f[x1][y1] <= c[x][y]-50)
    {
        if (h <= c[x1][y1]-50)
        {
            if (h-f[x][y] >= 20) return 1;
            else return 10;
        }
        else {
                if (c[x1][y1]-50 >= 0)
                {
                    double t = 1.0*(h-c[x1][y1]+50)/10;
                    if (c[x1][y1]-50-f[x][y] >= 20) return t+1;
                    else return t+10;
                }
                else return oo;
             }
    }
    else return oo;
}

void dfs(int x, int y)
{
    int x1, y1;

    for (int i = 0;i < 4;++i)
    {
        x1 = x+fx[i][0];
        y1 = y+fx[i][1];
        if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && !fl[x1][y1]
                && (ifenter(x,y,x1,y1,h)))
        {
            ++r;
            l[r][0] = x1; l[r][1] = y1;
            g[x1][y1] = 0;
            fl[x1][y1] = true;
          //  cout << x1 << ' ' << y1 << endl;
            dfs(x1,y1);
        }
    }
}

void doit()
{
    int t = 1, x, y, x1,y1;

    while (true)
    {
        x = l[t][0];
        y = l[t][1];
        for (int i = 0;i < 4;++i)
        {
            x1 = x+fx[i][0];
            y1 = y+fx[i][1];
            if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m )
            {
                double tmp = g[x][y] + enter(x,y,x1,y1,1.0*h-g[x][y]*10);
            //    cout << x1 << ' ' << y1 << ' ' << tmp << endl;
                if (tmp < g[x1][y1])
                {
                    g[x1][y1] = tmp;
                    if (!fl[x1][y1])
                    {
                        ++r;
                        if (r == MAXR) r = 1;
                        l[r][0] = x1; l[r][1] = y1;
                        fl[x1][y1] = true;
                    }
                }
            }
        }
        if (t == r) break;
        fl[x][y] = false;
        ++t;
        if ( t== MAXR) t = 1;
    }
    cout << g[n][m] << endl;

}

int main()
{
    freopen("B.in","r",stdin);
    freopen("b.out","w",stdout);
    cin >> t;
    for (int w = 1;w <= t;++w)
    {
        cin >> h >> n >> m;
        for (int i = 1;i <= n;++i)
            for (int j = 1;j <= m;++j)
                cin >> c[i][j];
        for (int i = 1;i <= n;++i)
            for (int j = 1;j <=m;++j)
                cin >> f[i][j];
        for (int i = 1;i <= n;++i)
            for (int j = 1;j <= m;++j)
            {
                g[i][j] = oo;fl[i][j]= false;
            }
        cout << "Case #" << w << ": ";
        g[1][1] = 0; r = 1;
        l[1][0] = 1; l[1][1] = 1; fl[1][1]= true;
        dfs(1,1);
        doit();
    }

    return 0;

}
