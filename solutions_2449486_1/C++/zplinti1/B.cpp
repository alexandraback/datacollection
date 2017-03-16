#include <stdio.h>
#include <string.h>

const int maxn=100;

int a[maxn][maxn],low[maxn],col[maxn];

int main()
{
    int cas,n,m;

    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d",&cas);
    for(int ii=1;ii<=cas;ii++)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
        for(int i=0;i<n;i++)
        {
            low[i]=0;
            for(int j=0;j<m;j++)
             if (a[i][j]>low[i]) low[i]=a[i][j];
        }
        for(int j=0;j<m;j++)
        {
            col[j]=0;
            for(int i=0;i<n;i++)
             if (a[i][j]>col[j]) col[j]=a[i][j];
        }
        bool good=1;
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
          if (a[i][j]!=low[i]&&a[i][j]!=col[j]) good=0;
        printf("Case #%d: ",ii);
        if (good) puts("YES");
        else puts("NO");
    }
    return 0;
}
