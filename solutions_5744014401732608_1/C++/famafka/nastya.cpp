#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
long long m;
int b[101][101];
long long dp[101];

void go(int x,long long m)
{
    for(int i=2;i<n;i++)
        for(int j=i+1;j<=n;j++)
            b[i][j]=1;
    for(int i=2;i<=n;i++)
        if(dp[i]<=m)
        {
            m-=dp[i];
            b[1][i]=1;
        }
}

void solve1(bool f)
{
    if(!f)
    {
        cout<<"IMPOSSIBLE\n";
        return;
    }else
    {
        cout<<"POSSIBLE\n";
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                b[i][j]=0;
        go(1,m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                cout<<b[i][j];
            cout<<"\n";
        }
    }
}

main()
{
    freopen("Bbig.in","r",stdin);
    freopen("Bbig.out","w",stdout);
    int t;
    cin>>t;
    for(int t1=1;t1<=t;t1++)
    {
        cout<<"Case #"<<t1<<": ";
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            dp[i]=0;
        dp[n]=1;
        for(int i=n-1;i>=1;i--)
            for(int j=i+1;j<=n;j++)
                dp[i]+=dp[j];
        if(dp[1]>=m)
            solve1(1);
        else
            solve1(0);
    }
}
