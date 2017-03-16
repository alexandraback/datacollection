#include <stdio.h>
#include <algorithm>
#define LLM 2000000000000000000
#define MAX 1000000000LL
typedef long long I64;

I64 bs(I64 k, I64 n)
{
	I64 l = 0, r = LLM / std::max(MAX, k * 2) + 1, m;

	while (l < r)
	{
		m = (l + r) / 2;
		if ((2 * m + 2 * k - 1) * m <= n)
			l = m + 1;
		else
			r = m;
	}
	return l - 1;
}

int main()
{
	int t, c = 1;
	I64 r, n, ans;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%lld %lld", &r, &n);

		ans = bs(r, n);

		printf("Case #%d: %lld\n", c++, ans);
	}
	return 0;
}
