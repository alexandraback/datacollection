#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=1000000+2;
int dp[2][maxn+1];

void ck(int &x,int y)
{
    if (y<x) x=y;
}

int a[1000];

int main()
{
    int cas,A,n;

    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&cas);
    for(int ii=1;ii<=cas;ii++)
    {
        scanf("%d%d",&A,&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        printf("Case #%d: ",ii);
        if (A==1)
        {
            printf("%d\n",n);
            continue;
        }
        memset(dp,0x3f,sizeof(dp));
        dp[0][A]=0;
        int now=0,pre=1;
        for(int i=0;i<n;i++)
        {
            memset(dp[pre],0x3f,sizeof(dp[pre]));
            for(int j=2;j<=maxn;j++)
                if (dp[now][j]<=n)
                {
                    ck(dp[pre][j],dp[now][j]+1);
                    int k=0,nows=j;
                    while(nows<=a[i])
                    {
                        nows+=nows-1;
                        k++;
                    }
                    nows+=a[i];
                    if (nows>maxn) nows=maxn;
                    ck(dp[pre][nows],dp[now][j]+k);
                }
            now^=1;pre^=1;
        }
        int ans=n;
        for(int i=0;i<=maxn;i++)
            ck(ans,dp[now][i]);
        printf("%d\n",ans);
    }
    return 0;
}

