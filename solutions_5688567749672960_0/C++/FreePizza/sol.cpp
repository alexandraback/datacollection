#include <bits/stdc++.h>
using namespace std;
int dp[1000010];
void prec()
{
    long int i,k;
    string s;
    memset(dp,0x3f,sizeof(dp));
    dp[1] = 1;
    for(i=1;i<1000000;i++)
    {
        s=to_string(i);
        reverse(s.begin(),s.end());
        k=stoi(s);
        dp[i+1]=min(dp[i+1],dp[i]+1);
        dp[k]=min(dp[k],dp[i]+1);
    }
}
int main()
{
    prec();
    long int i,n,t,p;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>p;
        cout<<"Case #"<<i<<": "<<dp[p]<<"\n";
    }
    return 0;
}

