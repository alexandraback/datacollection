#include <bits/stdc++.h>

using namespace std;
int dp[10000009];
int rever(int x)
{
    int u=0;
    while(x!=0)
    {
        u=u*10+x%10;
        x/=10;
    }//cout<<u<<endl;
    return u;
}

int main()
{
    memset(dp,1000009,sizeof(dp));
    //rever(8910);
    dp[1]=1;
    for(int i=1;i<=1000000;i++)
    {
        dp[i+1]=min(dp[i+1],dp[i]+1);
        dp[rever(i)]=min(dp[rever(i)],dp[i]+1);
        //cout<<dp[rever(i)]<<endl;
    }
    //for(int i=1;i<100;i++)cout<<dp[i]<<" ";
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        cout<<"Case #"<<i<<": ";
        cout<<dp[n];
        cout<<endl;
    }
}
