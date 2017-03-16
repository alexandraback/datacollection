#include<iostream>
using namespace std;
int dp[1001000];
int re(int i)
{
    int ret=0;
    while(i!=0)
    {
        ret*=10;
        ret+=(i%10);
        i/=10;
    }
    return ret;
}
int main()
{
    int i,j,k;
    int n,t;
    cin>>t;
    int c=1;
    dp[0]=0;
    for(i=1;i<1000020;i++)
    {
        dp[i]=dp[i-1];
        j=re(i);
        k=re(j);

        if(k==i && j<i && dp[j]<dp[i])
        {
           // cout<<i<<' '<<j<<' '<<dp[j]<<endl;
            dp[i]=dp[j];
        }
        dp[i]++;
    }
    while(t--)
    {
        cin>>n;
        cout<<"Case #"<<c<<": "<<dp[n]<<endl;
        c++;
    }
}
