#include <cstdio>

int cnt, a[20], test;
long long num[100000], A, B;

bool check(long long x)
{
	a[0] = 0;
	while (x > 0)
	{
		a[++a[0]] = x % 10;
		x /= 10;
	}
	for (int i = 1; i <= a[0] / 2; ++i)
		if (a[i] != a[a[0] - i + 1])
			return 0;
	return 1;
}

int main()
{
	int cnt = 0;
	for (int i = 1; i <= 10000000; ++i)
		if (check(i) && check((long long)i * i))
			num[++cnt] = (long long)i * i;
	/*printf("%d\n", cnt);
	for (int i = 1; i <= cnt; ++i)
		printf("%I64d\n", num[i]);*/
	scanf("%d", &test);
	for (int kase = 1; kase <= test; ++kase)
	{
		scanf("%I64d %I64d", &A, &B);
		int ans = 0;
		for (int i = 1; i <= cnt; ++i)
			if (A <= num[i] && num[i] <= B)
				++ans;
		printf("Case #%d: %d\n", kase, ans);
	}
	
	return 0;
}
