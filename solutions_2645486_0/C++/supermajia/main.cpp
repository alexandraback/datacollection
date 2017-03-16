#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
double pi = acos(-1);
int T;
int n,e,r;
int data[105];
int dp[105][6];
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out3.txt","w",stdout);
    int cas =1;
    cin>>T;
    while(T--)
    {
        cin>>e>>r>>n;
        for(int i=1;i<=n;i++)
            cin>>data[i];
        memset(dp,0,sizeof(dp));
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=min(r,e);j<=e;j++)
            {
                int t = j-min(r,e);
                for(int k=t;k<=e;k++)    //j
                {
//                    if(j==2)
//                        cout<<k<<endl;
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+data[i]*(k-t));
                    ans=max(ans,dp[i][j]);
                }
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
