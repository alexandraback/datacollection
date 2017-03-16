#include <stdio.h>
#include <math.h>

long long r, t;
long long b;

// 2n^2+b*n-t

long long judge(long long n)
{
	return 2*n*n+b*n-t;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int T, nt = 0;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld%lld", &r, &t);
		b = 2*r-1;
		long long right = (long long)sqrt(0.5*t) + 1;
		if (right > (t/b+1))
			right = t/b +1;
		long long left = 1;
		
		while(left+1 < right)
		{
			long long mid = (right+left)/2;
			if (judge(mid)<=0)
				left = mid;
			else
				right = mid;
		}
		printf("Case #%d: %lld\n", ++nt, left);
	}
	return 0;
}