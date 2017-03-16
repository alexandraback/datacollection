#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int t,e,r,n;
int v[110];
int dp[110][110];
int main ()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("out3.txt","w",stdout);
    cin>>t;
    for(int Case=1; Case<=t; Case++)
    {
        cin>>e>>r>>n;
        for(int i=0; i<n; i++)
            cin>>v[i];
        memset(dp,0,sizeof(dp));
        int p=e;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=e; j++)
            {
                for(int k=0; k<=j; k++)
                {
                    if(j-k>=0)
                    {
                        if(dp[i-1][j]<dp[i-1][j-k+r]+k*v[i-1])
                        {
                            dp[i][j]=dp[i-1][j-k+r]+k*v[i-1];
                            //cout<<i<<":"<<k<<endl;
                        }
                    }
                    //dp[i][j]=max(dp[i-1][j],dp[i-1][j-k+r]+k*v[i-1]);
                }
            }
        }
        printf("Case #%d: %d\n",Case,dp[n][e]);
    }
}
