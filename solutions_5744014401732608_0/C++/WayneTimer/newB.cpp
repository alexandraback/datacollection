#include <cstdio>
#include <cstring>

int b,v,ans;
long long m,s;
int a[60][60];

void check(int x)
{
    if (x==b)
    {
        ans++;
        return;
    }
    for (int i=x+1;i<=b;i++)
        if (a[x][i])
            check(i);
}

bool dfs(int x,int y)
{
    if (x==b)
    {
        ans = 0;
        check(1);
        if (ans==m)
            return true;
        return false;
    }

    bool flag = false;
    a[x][y]=1;
    if (y+1<=b)
        flag = dfs(x,y+1);
    else
        flag = dfs(x+1,x+2);

    if (flag) return true;

    a[x][y]=0;
    if (y+1<=b)
        flag = dfs(x,y+1);
    else
        flag = dfs(x+1,x+2);

    return flag;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int o=1;o<=T;o++)
    {
        scanf("%d %lld",&b,&m);
        printf("Case #%d: ",o);
        memset(a,0,sizeof(a));
        if (dfs(1,2))
        {
            puts("POSSIBLE");
            for (int i=1;i<=b;i++)
            {
                for (int j=1;j<=b;j++)
                    printf("%d",a[i][j]);
                puts("");
            }
        }
        else
            puts("IMPOSSIBLE");
    }
    return 0;
}
