#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[105][105];
int data[105];
int n,s,p;
int solve()
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        int low = max(0,data[i]/3-1);
        int high = min(data[i]/3+1,10);
        for(int t1=low;t1<=high;t1++)
        {
            int t3 = t1;
            int t2 = data[i]-t1-t3;
            if(t2>t3||t2<t1)
                continue;
            for(int j=0;j<=s;j++)
            {
                if(t3>=p)
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
                else
                    dp[i][j]=max(dp[i][j],dp[i-1][j]);
            }
        }
        for(int t1=low;t1<=high;t1++)
        {
            int t3 = t1+1;
            if(t3>10)
                continue;
            int t2 = data[i]-t1-t3;
            if(t2>t3||t2<t1)
                continue;
            for(int j=0;j<=s;j++)
            {
                if(t3>=p)
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
                else
                    dp[i][j]=max(dp[i][j],dp[i-1][j]);
            }
        }
        for(int t1=low;t1<=high;t1++)
        {
            int t3=t1+2;
            if(t3>10)
                continue;
            int t2 = data[i]-t1-t3;
            if(t2>t3||t2<t1)
                continue;
            for(int j=1;j<=s;j++)
            {
                if(t3>=p)
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                else
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
            }
        }
    }
    return dp[n][s];
}
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    int cas =1;
    while(t--)
    {
        cin>>n>>s>>p;
        for(int i=1;i<=n;i++)
            cin>>data[i];
        int ans = solve();
        cout<<"Case #"<<cas++<<": "<<ans<<endl;
    }
    return 0;
}
