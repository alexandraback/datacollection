#include <iostream>
#include <cmath>
using namespace std;
long long gcd(long long  a,long long b)
{ 
	long long temp;
	while(a%b)   
	  {   
	   temp=a;   
	   a=b;   
	   b=temp%b;              
	  }   
	  return b;
}
int main(int argc, char *argv[]) {
	int t,T;
	scanf("%d",&T);
	
	for(t=0;t<T;t++)
	{
		long long n,i,j,a,b,gcdn;
		
		scanf("%lld/%lld",&a,&b);
		gcdn=gcd(a,b);
		a/=gcdn;
		b/=gcdn;
		
		long long pwr=0,tmp=b;
		
		while(tmp%2==0)
		{
			tmp/=2;
			pwr++;
		}
		
		
		if(tmp!=1)printf("Case #%d: impossible\n",t+1);
		else{
		int ans=0;
		while(a*2<b)
				{
					a*=2;
					ans++;
				}
				ans++;
				
		printf("Case #%d: %d\n",t+1,ans);
		}
		
	}
}