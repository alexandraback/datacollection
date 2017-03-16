#include<stdio.h>
long long  gcd(long long  a,long long  b)
{
	if(b == 0ll)
		return a;
	else
		return gcd(b,a % b);
}
int main(void)
{
	int t,T,i,ans;
	long long a,b,c;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%lld/%lld",&a,&b);
		printf("Case #%d: ",t);
		if(a == 0 || b == 0 || a > b)
		{
			printf("impossible\n");
			continue;
		}
		c = gcd(a,b);
		a /= c;
		b /= c;
		c = b;
		while(c % 2 == 0)
			c /= 2;
		if(c != 1)
		{
			printf("impossible\n");
			continue;
		}
		ans = 0;
		while(a < b)
		{
			a = a * 2;
			ans += 1;
		}	
		printf("%d\n",ans);
	}
	return 0;
}
