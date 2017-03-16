#include <stdio.h>
long long gcd(long long x, long long y) { return !y?x:gcd(y, x%y); }
int main()
{
	int ts;
	scanf("%d", &ts);
	for(int t=1; t<=ts; t++)
	{
		long long a, b, g, r;
		scanf("%lld/%lld", &a, &b);
		printf("Case #%d: ", t);
		g=gcd(a, b);
		a/=g;
		b/=g;
		if(b&(b-1)) printf("impossible\n");
		else
		{
			for(r=0; a<b; r++, a*=2);
			printf("%lld\n", r);
		}
	}
	return 0;
}
