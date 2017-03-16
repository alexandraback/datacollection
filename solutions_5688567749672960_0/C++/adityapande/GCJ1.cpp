#include<stdio.h>
#include <queue>  
#include<iostream>
//bfs idea...

//dp idea

using namespace std;


int rev(int n)
{
    int a = n%10;
    n/=10;
    while(n)
    {
            a*=10;
            a+=n%10;
            n/=10;
    }
    return a;
}


int dp[1000001];
int main()
{
    freopen ("out1.txt","w",stdout);
    freopen ("A-small-attempt0.in","r",stdin);
    int t,smax,cas=0;
    
    
    dp[1] = 1;
    dp[0] = 0;
    for(int i=2;i<1000001;i++)
    {
            dp[i]=dp[i-1]+1;
            if(i%10)
            {
                 int tm = rev(i);
                 if(tm<i && dp[tm]<dp[i]) dp[i]=dp[tm]+1;
            }
    }
    
   cin>>t;
    
    while(cas++<t)
    {
          cin>>smax;
          printf("Case #%d: %d\n",cas,dp[smax]);
    }
    scanf("%*d");
    return 0;  
}
