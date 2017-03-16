#include <iostream>
#include<algorithm>
#include<cstring>

using namespace std;

long long ans,n,m,w,dp[100];

int main()
{
    int qw;
    cin>>qw;
    for(int q=1;q<=qw;q++)
    {
        cin>>n>>m>>w;
        memset(dp,127,sizeof dp);
        ans=(n-1)*(m/w);
        for(int i=0;i<w;i++)
            dp[i]=0;
        for(int i=w;i<=m;i++){
            for(int j=1;j<=i;j++)
                dp[i]=min(dp[i],max(min((j-1)/w+dp[i-j],(i-j)/w+dp[j-1])+1,(i>w?w+1:w)));
            //cout<<i<<" "<<dp[i]<<endl;
        }
        cout<<"Case #"<<q<<": "<<dp[m]+ans<<endl;
    }
}
