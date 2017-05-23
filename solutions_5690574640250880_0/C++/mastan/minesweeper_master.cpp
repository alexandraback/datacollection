#include <cstdio>
#include <algorithm>

using namespace std;

char base[105][105];

int main()
{
    freopen("D:/tp.txt","r",stdin);
    freopen("D:/out.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for (int id=1; id<=tc; id++)
    {
        printf("Case #%d:\n",id);
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int free=n*m-k;
        if (free==1)
        {
            printf("c");
            for (int i=1; i<=n; i++)
            {
                for (int j=1; j<=m; j++)
                    if (i+j!=2)
                        printf("*");
                printf("\n");
            }
            continue;
        }
        if (n==1)
        {
            printf("c");
            for (int i=2; i<=free; i++)
                printf(".");
            for (int i=free+1; i<=m; i++)
                printf("*");
            printf("\n");
            continue;
        }
        if (m==1)
        {
            printf("c\n");
            for (int i=2; i<=free; i++)
                printf(".\n");
            for (int i=free+1; i<=n; i++)
                printf("*\n");
            continue;
        }
        if (free==2 || free==3 || free==5 || free==7)
        {
            printf("Impossible\n");
            continue;
        }
        if (n==2)
        {
            if (free%2==1)
            {
                printf("Impossible\n");
                continue;
            }
            printf("c");
            for (int i=2; i<=free/2; i++)
                printf(".");
            for (int i=free/2+1; i<=m; i++)
                printf("*");
            printf("\n");
            for (int i=1; i<=free/2; i++)
                printf(".");
            for (int i=free/2+1; i<=m; i++)
                printf("*");
            printf("\n");
            continue;
        }
        if (m==2)
        {
            if (free%2==1)
            {
                printf("Impossible\n");
                continue;
            }
            printf("c.\n");
            for (int i=2; i<=free/2; i++)
                printf("..\n");
            for (int i=free/2+1; i<=n; i++)
                printf("**\n");
            continue;
        }
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                base[i][j]='*';
        base[1][1]='c';
        base[1][2]='.';
        base[2][1]='.';
        base[2][2]='.';
        free-=4;
        if (free>1)
        {
            base[1][3]='.';
            base[2][3]='.';
            free-=2;
        }
        int pl=3;
        while (pl<=n && free>1)
        {
            base[pl][1]='.';
            base[pl][2]='.';
            pl++;
            free-=2;
        }
        pl=4;
        while (pl<=m && free>1)
        {
            base[1][pl]='.';
            base[2][pl]='.';
            pl++;
            free-=2;
        }
        for (int i=3; i<=n; i++)
            for (int j=3; j<=m; j++)
                if (free>0)
                {
                    base[i][j]='.';
                    free--;
                }
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
                printf("%c",base[i][j]);
            printf("\n");
        }
    }
}
