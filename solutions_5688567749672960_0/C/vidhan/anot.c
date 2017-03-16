#include <stdio.h>
#include <string.h>
#define min(a,b) a<b?a:b
#define ll long long int
#define INT_MAX 100000000000000
//VIDHAN JAIN
ll rev(ll n)
{
	ll d,r; 
	while(n!=0)
   {
     d=n%10;
     r=(r*10)+d;
     n=n/10;
   }
   return r;
}
ll func(ll num)
{
	ll n = num,r,ans=INT_MAX;
	while((n%10)!=n && n!=10)
	{
		if(n%10==0)
			break;
		r = rev(n);
		if(r<n)
		ans = min(ans, r);
		n--;
	}
	if(ans!=INT_MAX)
		return ans;
	return 0;
}
int main() 
{
	int i,t;
	ll n,ans;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%lld",&n);
		printf("Case #%d: ",i);
		if(n%10==n)
		{
			printf("%lld\n",n);
			continue;
		}
		ans = func(n);
		if(ans!=0)
			 printf("%lld\n",ans+(n-rev(ans)+1));
		else 
			printf("%lld\n",n);
	}
	return 0;
}
