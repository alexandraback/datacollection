#include <cstdio>
#include <cmath>

long double r, t;

bool ok(unsigned long long n)
{
	long double val = 2 * n * n + 2 * n * r - n;
	return val <= t;
}

int main()
{
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; ++i)
	{
		
		scanf("%llf %llf", &r, &t);
		
		unsigned long long low = 1;
		unsigned long long high = 9000000000000000000;
		
		while (high - low > 1)
		{
			long long mid = (low + high) / 2;
			
			if (ok(mid))
				low = mid;
			else
				high = mid;
		}
		
		unsigned long long res;
		if (high - low == 0 || ok(high))
			res = high;
		else
			res = low;
		
		printf("Case #%d: %lld\n", i + 1, res); 
	}
	
	return 0;
}
