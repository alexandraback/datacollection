#include<bits/stdc++.h>
using namespace std;


int ans[60][60];
long long dp[60];
int main()
{
    freopen("1.in","r",stdin);
    freopen("2.txt","w",stdout);
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int n,m;scanf("%d%d",&n,&m);
        memset(ans,0,sizeof(ans));
        memset(dp,0,sizeof(dp));
        int div=((n-2)/2+1)/2;
        dp[1]=1;
        for(int i=2;i<n;i++)
        {
            for(int j=1;j<i;j++)
            {
                ans[j][i]=1;
                dp[i]+=dp[j];
            }
        }
        for(int i=n-1;i>=1;i--)
            if(m>=dp[i])
            {
                ans[i][n]=1;
                m-=dp[i];
            }
        if(m)
        {
            printf("Case #%d: IMPOSSIBLE\n",ti++);
        }
        else
        {
            printf("Case #%d: POSSIBLE\n",ti++);
            for(int i=1;i<=n;i++,putchar(10))
                for(int j=1;j<=n;j++)
                    printf("%d",ans[i][j]);
        }
    }
	return 0;
}
