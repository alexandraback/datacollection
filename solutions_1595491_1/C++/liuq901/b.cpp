#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool ok[40][20][2];
int f[110][110];
void init()
{
    for (int i=0;i<=10;i++)
        for (int j=i;j<=i+2;j++)
            for (int k=j;k<=i+2;k++)
            {
                int sum=i+j+k;
                bool flag=k==i+2;
                ok[sum][k][flag]=true;
            }
    for (int i=0;i<=30;i++)
        for (int j=9;j>=0;j--)
            for (int k=0;k<=1;k++)
                if (ok[i][j+1][k])
                    ok[i][j][k]=true;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,v;
        scanf("%d%d%d",&n,&m,&v);
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            for (int j=0;j<=m;j++)
            {
                f[i][j]=max(f[i][j],f[i-1][j]+ok[x][v][0]);
                if (j>0)
                    f[i][j]=max(f[i][j],f[i-1][j-1]+ok[x][v][1]);
            }
        }
        static int id=0;
        printf("Case #%d: %d\n",++id,f[n][m]);
    }
    return(0);
}

