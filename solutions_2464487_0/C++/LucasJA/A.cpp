#include <cstdio>
#include <cmath>

int main()
{
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; ++i)
	{
		double r, t;
		scanf("%lf %lf", &r, &t);
		
		double d = 4 * r * r - 4 * r + 1 + 8 * t;
		d = sqrt(d);
		double n = - 2 * r + 1 + d;
		n /= 4;
		
		printf("Case #%d: %lld\n", i + 1, (long long) n); 
	}
	
	return 0;
}
