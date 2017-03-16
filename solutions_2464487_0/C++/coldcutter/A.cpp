#include <cstdio>

long long r, t;
int test;

long long calc(long long r, long long t)
{
	long long left = 1, right = 1000000001;
	while (left + 1 < right)
	{
		long long m = (left + right) >> 1;
		if (m * 2 + r * 2 - 1 <= t / m)
			left = m;
		else
			right = m;
	}
	return left;
}

int main()
{
	scanf("%d", &test);
	for (int kase = 1; kase <= test; ++kase)
	{
		scanf("%I64d %I64d", &r, &t);
		printf("Case #%d: %I64d\n", kase, calc(r, t));
	}
	
	return 0;
}