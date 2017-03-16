#include <stdio.h>
#include <algorithm>

int sz;
long long ans[10000000];

bool foo(long long n)
{
	int len = 0, a[20];
	for (; n; n /= 10) a[len++] = n % 10;
	for (int i = 0; i < len; ++i) if (a[i] != a[len - i - 1]) return false;
	return true;
}

int main()
{
	for (long long i = 1; i <= 10000000; ++i) {
		if (foo(i) && foo(i * i)) ans[sz++] = i * i;
	}
	int dat;
	scanf("%d", &dat);
	for (int k = 1; k <= dat; ++k) {
		long long a, b;
		scanf("%lld%lld", &a, &b);
		int s = std::upper_bound(ans, ans + sz, b)
			- std::lower_bound(ans, ans + sz, a);
		printf("Case #%d: %d\n", k, s);
	}
}
