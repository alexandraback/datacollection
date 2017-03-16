#include <cstdio>

int main()
{
	int c;
	scanf("%d", &c);
	for (int i=1; i<=c; ++i)
	{
		long long r, t;
		scanf("%lld %lld", &r, &t);

		long long lo = 1;
		long long hi = 1000000000;
		while ((lo+1)<hi)
		{
			long long mid = (lo+hi)/2;
			long long res = (long long)2*mid + (2*r-1);
			if ((double)res<=(double)t/mid)
				lo = mid;
			else
				hi = mid;
		}

		printf("Case #%d: %d\n", i, lo);
	}
	
	return 0;
}