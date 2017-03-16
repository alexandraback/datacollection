#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200
using namespace std;

int map[N][N];
int row[N],column[N];

int main()
{
    int n,m,i,j,t,ans,ys;

    freopen("B-small-attempt1.in","r",stdin);
    freopen("dataBsmall.out","w",stdout);
    scanf("%d",&t);
    ys=0;
    while (t--)
    {
        scanf("%d%d",&n,&m);
        for (i=0;i<n;i++)
            for (j=0;j<m;j++)
                scanf("%d",&map[i][j]);
        for (i=0;i<n;i++)
        {
            row[i]=map[i][0];
            for (j=0;j<m;j++)
                row[i]=max(row[i],map[i][j]);
        }
        for (i=0;i<m;i++)
        {
            column[i]=map[0][i];
            for (j=0;j<n;j++)
                column[i]=max(column[i],map[j][i]);
        }
        ans=1;
        for (i=0;i<n&&ans;i++)
            for (j=0;j<m&&ans;j++)
                if (map[i][j]<row[i]&&map[i][j]<column[j])
                    ans=0;
        if (ans)
            printf("Case #%d: YES\n",++ys);
        else
            printf("Case #%d: NO\n",++ys);
    }

    return 0;
}
