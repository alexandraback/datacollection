#include <stdio.h>
#include <stdarg.h>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#define clr(a) memset(a, 0, sizeof(a))

typedef long long ll;
typedef std::pair<int, int> pii;
#define DEBUG 1

void dbg(const char * fmt, ...)
{
#if DEBUG
	va_list args;
	va_start(args, fmt);
	vfprintf(stdout, fmt, args);
	va_end(args);
#endif
}

std::map<ll, ll> sums;
ll ar[500];

ll rnd()
{
	return (ll)rand() << 31 ^ (ll)rand();
}

void print_ans(ll a, ll b)
{
	ll mask = a & (~b);
	for(int i = 0; i < 50; i++)
		if ((mask & (1LL << i)) != 0)
			printf("%lld ", ar[i]);
	printf("\n");
	mask = b & (~a);
	for(int i = 0; i < 50; i++)
		if ((mask & (1LL << i)) != 0)
			printf("%lld ", ar[i]);
	printf("\n");
}

void solve(int test_case)
{
	printf("Case #%d:\n", test_case);
	sums.clear();
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%lld", &ar[i]);
	std::sort(ar, ar+n);
	n = std::min(n, 50);
	ll max = (1LL << n) - 1;
	while(1)
	{
		ll sum = 0;
		ll mask = rnd() & max;
		for(int i = 0; i < n; i++)
			if (((1<<i) & mask) != 0)
				sum += ar[i];
		auto it = sums.find(sum);
		if (it == sums.end())
		{
			sums.insert(std::make_pair(sum, mask));
		}
		else if (it->second == mask)
			continue;
		else
		{
			print_ans(mask, it->second);
			return;
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		solve(i);

	return 0;
}
