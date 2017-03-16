#include<bits/stdc++.h>
#define lli long long int
using namespace std;
lli rev(lli n)
{
   lli b,c=0;

   while(n>0)
   {
       b=n%10;
       c=c*10+b;
       n/=10;
   }

   return c;
}
lli dp[1000005];
lli pre()
{
	dp[0]=0;
   for(int  i=1;i<=10;i++)
   {
   	dp[i]=dp[i-1]+1;
   }
   for(int i=11;i<=1000000;i++)
   {
   		lli x=rev(i);
   		if(x!=i && dp[x]!=-1 && i%10!=0)
   		{
			dp[i]=min(dp[i-1]+1,dp[x]+1);
   		}
   		else{
   			dp[i]=dp[i-1]+1;
   		}
   }
}
int main()
{
   int T,i;
   lli n;
   for(i=1;i<=1000005;i++)
   	dp[i]=-1;
   pre();
   scanf("%d",&T);
   for(i=1;i<=T;i++)
   {
       scanf("%lld",&n);
       printf("Case #%d: %lld\n",i,dp[n]);
   }
   return 0;
}
