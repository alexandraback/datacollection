#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
long long gcd(long long  a, long long b){ return a == 0 ? b : gcd(b % a, a); }
int main(void)
{
   int n,T,tt,i,ans;
   cin>>T;
   tt=T;
   int flag;
   long long p,q,gg,r;
   for(tt=1;tt<=T;tt++)
   {
	   ans=0;
      scanf("%lld/%lld",&p,&q);
      gg=gcd(p,q);
      p/=gg;
      q/=gg;
      for(i=1,r=1;i<=40;i++)
      {
    	  flag=0;
    	  r=pow(2,i);
    	  if(r==q)
    	  {
    		  flag=1;
    		  break;
    	  }
      }
      if(flag==0)
      {
    	  printf("Case #%d: impossible\n",tt);
    	  continue;
      }
      if(p>=q/2)
      {
    	  printf("Case #%d: 1\n",tt);
    	  continue;
      }
      for(i=1;i<=40;i++)
      {
    	  p=p*2;
          if(p>=q/2)
          {
        	 ans=i+1;
        	 break;
          }
      }
      if(ans==0)
    	  printf("Case #%d: impossible\n",tt);
      else
	   printf("Case #%d: %d\n",tt,ans);
   }
   return 0;
}