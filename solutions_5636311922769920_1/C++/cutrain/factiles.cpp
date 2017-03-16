#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

long long k, c, s;

long long posi(long long seg, long long po, long long base)
{
	return k * (seg - 1) + po;
}

long long solve(long long start, long long t)
{
	long long po = start;
	long long base = k;
	for (long long i = 1;i < t;++ i)
	{
		if (start == k)
			po = posi(po, start, base);
		else
			po = posi(po, ++ start, base);
		base *= k;
	}
	return po;
}

int main()
{
//	freopen("D-large.in","r",stdin);
//	freopen("factiles.out","w",stdout);
	int T;
	scanf("%d", &T);
	for (int testcase = 1;testcase <= T;++ testcase)
	{
		printf("Case #%d: ", testcase);
		scanf("%I64d%I64d%I64d", &k, &c, &s);
		long long x = (k - 1) / c + 1;
		if (x > s)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		for (long long i = 1;i <= x;++ i)
			printf("%I64d ", solve(c * (i - 1) + 1, c) );
		printf("\n");
	}
	return 0;
}
