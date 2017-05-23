#include <stdio.h>
#include <string.h>
#include "algorithm"
#include "iostream"

using namespace std;

struct point
{
    char start, end;
} node[14];

int map[1000][1000], vis[1000][1000];

int dfs(int x, int y)
{
    int sum=0;
    vis[x][y]=1;
    if(vis[x-1][y]==0&&map[x-1][y]==1)
    {
        sum+=dfs(x-1, y);
    }
    if(vis[x+1][y]==0&&map[x+1][y]==1)
    {
        sum+=dfs(x+1, y);
    }
    if(vis[x][y-1]==0&&map[x][y-1]==1)
    {
        sum+=dfs(x, y-1);
    }
    if(vis[x][y+1]==0&&map[x][y+1]==1)
    {
        sum+=dfs(x, y+1);
    }
    if(map[x-1][y]==0||map[x+1][y]==0||map[x][y+1]==0||map[x][y-1]==0)
    sum++;

    return sum;
}

main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T, m, n, k, r, sx, sy, x, y, i, j, cas=0;


    scanf("%d", &T);

    while(T--)
    {
        scanf("%d %d %d", &m, &n, &k);
        memset(map, 0, sizeof(map));
        memset(vis, 0, sizeof(vis));
        if(m>n)
        {
            r=m, m=n, n=r;
        }
        sx=(n+1)/2;
        sy=(m+1)/2;

        k--;
        map[sx][sy]=1;
        for(i=1; k>0; i++)
        {
            for(x=sx-1, y=sy-i+1, j=1; j<=i&&k>0; j++, x--, y++)
            {
                if(x>=1&&x<=n&&y>=1&&y<=m)
                {
                    k--;
                    map[x][y]=1;
                }
            }
            for(x=sx-i+1, y=sy+1, j=1; j<=i&&k>0; j++, x++, y++)
            {
                if(x>=1&&x<=n&&y>=1&&y<=m)
                {
                    k--;
                    map[x][y]=1;
                }
            }
            for(x=sx+1, y=sy+i-1, j=1; j<=i&&k>0; j++, x++, y--)
            {
                if(x>=1&&x<=n&&y>=1&&y<=m)
                {
                    k--;
                    map[x][y]=1;
                }
            }
            for(x=sx+i-1, y=sy-1, j=1; j<=i&&k>0; j++, x--, y++)
            {
                if(x>=1&&x<=n&&y>=1&&y<=m)
                {
                    k--;
                    map[x][y]=1;
                }
            }
        }
        printf("Case #%d: %d\n", ++cas, dfs(sx, sy));
    }


    return 0;
}
