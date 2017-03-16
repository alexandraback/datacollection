#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

long long int gcd(long long int a, long long int b)
{
	while (b != 0)
	{
		a = a % b;
		swap(a, b);
	}
	return a;
}

bool check(long long int a)
{
	double temp = log2((double)a);
	double p = floor(temp);
	if ( p == temp)
		return true;
	return false;
}

int main()
{
	long long int t;
	scanf("%lld",&t);
	
	for (long long int tcase = 1; tcase <= t; tcase++)
	{
		long long int p,q;
		scanf("%lld/%lld", &p, &q);
		long long int temp = gcd(p, q);
		p /= temp;
		q /= temp;
		printf("Case #%lld: ", tcase);
		if (!check(q))
		{
			printf("impossible\n");
			continue;
		}
		else
		{
			double k = (double)q/p;
			long long int ans = ceil(log2(k));
			printf("%lld\n", ans);
		}
	}

	return 0;
}