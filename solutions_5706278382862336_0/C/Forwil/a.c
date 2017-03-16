#include<stdio.h>
int gcd(int a,int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b,a % b);
}
int main(void)
{
	int t,T,i,a,b,c,ans;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d/%d",&a,&b);
		printf("Case #%d: ",t);
		if(a == 0)
		{
			printf("1\n");
			continue;
		}
		if(b == 0 || a > b)
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
