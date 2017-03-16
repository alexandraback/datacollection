#include <cstdio>
int n,m,a[101][101];
void fu(int lo)
{
    int l[101]={0},u[101]={0};
    if(lo==101)
    {
        printf("YES\n");
        return;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==lo||a[i][j]==-1)
            {
                u[j]=u[j]+1;
                l[i]=l[i]+1;
                continue;
            }
            if(a[i][j]<lo)
            {
                printf("NO\n");
                return;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(l[i]==m)
            for(int j=1;j<=m;j++)
                a[i][j]=-1;
    }
    for(int j=1;j<=m;j++)
    {
        if(u[j]==n)
            for(int i=1;i<=n;i++)
                a[i][j]=-1;
    }
    fu(lo+1);
}
int main()
{
    freopen("Tic.in","r",stdin);
    freopen("Whee.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d",&n,&m);
        for(int j=1;j<=n;j++)
            for(int k=1;k<=m;k++)
                scanf("%d",&a[j][k]);
        printf("Case #%d: ",i);
        fu(1);
    }
}
