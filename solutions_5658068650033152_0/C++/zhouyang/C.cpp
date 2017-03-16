#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define maxn 110
#define mod 1000000007
using namespace std;
int dx []= {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};
bool vis[maxn][maxn];
int n,m,k;
bool fit(int x, int y)
{
    if (!vis[x][y]) return false;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if (!(tx >= 0 && tx < n && ty >= 0 && ty < m)
                || !vis[tx][ty]) return true;
    }
    return false;
}
int calc(int c)
{
    memset(vis,false,sizeof(vis));
    for (int i = 0; i < n * m; i++)
    {
        if ((c & (1 << i)) != 0)
        {
            vis[i / m][i % m] = true;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (fit(i, j)) cnt++;
        }
    }
    return cnt;
}
int main()
{
   // freopen("C-small-attempt0.in","r",stdin);
    //freopen("C-small-attempt0.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int Case=1;Case<=t;++Case)
    {
        scanf("%d%d%d",&n,&m,&k);
        printf("Case #%d: ",Case);
       // memset(vis,false,false);
        int comp = (1 << k) - 1;
        int ans = k;
        while (comp < 1 << (n * m))
        {
            ans = min(ans, calc(comp));
            int x = comp & -comp, y = comp + x;
            comp = ((comp & ~y) / x >> 1) | y;
        }
        printf("%d\n",ans);
    }
}


