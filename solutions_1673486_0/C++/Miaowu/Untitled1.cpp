#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

double p[1000];
double pp[1000];
double daoh[1000];
double dp[100][100];

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int T,i,j,n,m,cnt=1;
    double tag,s;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&m,&n);
        for (i=0;i<m;i++)
        {
            scanf("%lf",&pp[i]);
        }
        tag=1;
        for (i=0;i<m;i++)
        {
            p[i]=tag*(1-pp[i]);
            tag=tag*pp[i];
        }
        p[i]=tag;
        memset(daoh,0,sizeof(daoh));
        for (i=0;i<=m;i++)
        {
            for (j=0;j<=m;j++)
            {
                if (i<m-j) dp[j][i]=p[i]*(j+n-m+j+n+2);
                else dp[j][i]=p[i]*(n-m+2*j+1);
                daoh[j]+=dp[j][i];
            }
        }
        s=0;
        for (i=0;i<=m;i++)
        {
            s+=p[i]*(2+n);
        }
        for (j=0;j<=m;j++)
        {
            s=min(daoh[j],s);
        }
        printf("Case #%d: %lf\n",cnt++,s);
    }
    return 0;
}
