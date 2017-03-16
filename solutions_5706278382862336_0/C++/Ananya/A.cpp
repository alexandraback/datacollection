#include <cstdio>
using namespace std;

long long gcd (long long x, long long y)
{
	if (x < y) return gcd(y,x);
	if (y == 0) return x;
	return gcd(y, x%y);
}

int powsOf2 (long long x)
{
	if (x%2==0) return 1+powsOf2(x/2);
	return 0;
}

int main ()
{
	int tc;
	scanf("%d", &tc);

	for (int tcase = 1; tcase <= tc; tcase++)
	{
		long long x, y;
		scanf("%lld/%lld", &x, &y);
		long long d = gcd(x,y);
		x /= d;
		y /= d;
		long long pow2 = powsOf2(y);

		if (y/(1<<pow2) != 1)
		{
			printf("Case #%d: impossible\n", tcase);
			continue;
		}

		long long gens = pow2;
		while ((x = x>>1)) gens--;

		if (gens == 0) printf("Case #%d: 1\n", tcase);
		else printf("Case #%d: %lld\n", tcase, gens);
	}
}