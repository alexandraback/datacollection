#include<bits/stdc++.h>
using namespace std;

int rev[1000001];
int dp[10000001],prev[10000001];

inline int reverse(int x)
{
    int rev=0;
    
    while(x)
    {
        rev=rev*10+(x%10);
        x/=10;
    }
    return rev;
}

int main()
{
    int T;
    
    for(int i=1;i<10000000;i++)
        rev[i]=reverse(i);
    //puts("here");
    for(int i=1;i<=20;i++)
        dp[i]=i;
    //puts("here");
    for(int i=21;i<10000000;i++)
    {
        dp[i]=dp[i-1]+1;
    }
    //puts("here");
    for(int i=21;i<10000000;i++)
    {
        if(i%10==0)
            dp[i]=dp[i-1]+1;
        else dp[i]=min(dp[i-1]+1,dp[rev[i]]+1);
    }
    
    //puts("here");
    cin>>T;
    
    int N;
    
    for(int t=1;t<=T;t++)
    {
        cin>>N;
        
        printf("Case #%d: %d\n",t,dp[N]);
    }
    return 0;
}

