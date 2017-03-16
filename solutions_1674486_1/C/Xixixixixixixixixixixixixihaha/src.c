#include <stdlib.h>
#include <stdio.h>

int path[1001][1001];
int inhert[1001][51];
int flag;

void find(int start, int level)
{
    int j;
    path[start][level] += 1;
    if (path[start][level] > 1)
    {
        flag = 1;
        return;
    }
    for (j = 1; j <= inhert[level][0]; j++)
    {
        find(start, inhert[level][j]);
        if (flag)
        {
            return;
        }
    }
}

int main()
{
    int t, n, m;
    int i, j, k, h;
    
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    
    scanf("%d", &t);
    for (k = 0; k < t; k++)
    {
        memset(path, 0, sizeof(path));
        memset(inhert, 0, sizeof(inhert));
        scanf("%d", &n);
        flag = 0;
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &m);
            inhert[i][0] = m;
            for (j = 1; j <= m; j++)
            {
                scanf("%d", &inhert[i][j]);
            }
        }
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= inhert[i][0]; j++)
            {
                find(i, inhert[i][j]);
                if (flag)
                {
                    goto output;
                }
            }
        }
        
    output:
        printf("Case #%d: ", k + 1);
        if (flag)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    freopen("CON", "r", stdin);     // 重定位回标准输入输出。。 
    freopen("CON", "w", stdout);
    return 0;
}
