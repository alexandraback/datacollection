#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=100+9;
int dp[maxn][maxn];

int t,s,p;
int v[maxn];
int ans[3];
int sup(int n)
{
    if(n%3==0)
    {
        ans[0]=n/3-1;
        ans[1]=n/3;
        ans[2]=n/3+1;
    }
    else if(n%3==1)
    {
        ans[0]=n/3-1;
        ans[1]=n/3+1;
        ans[2]=n/3+1;
    }
    else
    {
        ans[0]=n/3;
        ans[1]=n/3;
        ans[2]=n/3+2;
    }
}
void notsup(int n)
{
    if(n%3==0)
    {
        ans[0]=n/3;
        ans[1]=n/3;
        ans[2]=n/3;
    }
    else if(n%3==1)
    {
        ans[0]=n/3;
        ans[1]=n/3;
        ans[2]=n/3+1;
    }
    else if(n%3==2)
    {
        ans[0]=n/3;
        ans[1]=n/3+1;
        ans[2]=n/3+1;
    }
}
int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    scanf("%d",&t);
    int cot=1;
    int n;
    while(t--)
    {
        scanf("%d%d%d",&n,&s,&p);
        for(int i=1; i<=n; i++) scanf("%d",v+i);
        memset(dp,-1,sizeof(dp));
        dp[0][0]=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=s; j++)
            {

                dp[i][j] ;

                if(dp[i][j]==-1) continue;

                if(v[i+1]>1)
                {
                    sup(v[i+1]);
                    dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+(ans[2]>=p));
                }


                notsup(v[i+1]);
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]+(ans[2]>=p));

                dp[i+1][j]=max(dp[i+1][j],dp[i][j]);




            }
        }
        printf("Case #%d: %d\n",cot++,dp[n][s]);
    }






    return 0;
}







