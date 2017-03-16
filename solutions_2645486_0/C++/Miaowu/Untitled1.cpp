#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int a[100];
int dp[105][105];

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int i,j,n,e,r,T,cnt=1,k,ans,tmp;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&e,&r,&n);
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        memset(dp,0,sizeof(dp));
        for (i=0;i<n;i++)
        {
            for (j=0;j<=e;j++)
            {
        //        printf("%d ",dp[i][j]);
                for (k=0;k<=j;k++)
                {
                    tmp=min(j-k+r,e);
                    dp[i+1][tmp]=max(dp[i+1][tmp],dp[i][j]+k*a[i]);
                }
            }
      //      printf("\n");
        }
        ans=0;
        for (i=0;i<=e;i++)
        {
            ans=max(ans,dp[n][i]);
         //   printf("%d ",dp[n][i]);
        }
     //   printf("\n");
        printf("Case #%d: %d\n",cnt++,ans);
    }

}
