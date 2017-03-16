#include <stdio.h>
#include <stdarg.h>
#include <cstring>
#include <algorithm>
#include <set>
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


void solve(int test_case)
{
	printf("Case #%d: ", test_case);
	ll ans = 0;
	int a, b, k;
	scanf("%d%d%d", &a, &b, &k);
	k--;
	for(int i = 0; i < 31; i++)
		if (a & (1<<i))
			for(int j = 0; j < 31; j++)
			{
				if (b & (1<<j))
				{
					int msk_a = (1<<i) - 1;
					int top_a = a - (a & msk_a) - msk_a - 1;
					int msk_b = (1<<j) - 1;
					int top_b = b - (b & msk_b) - msk_b - 1;
					ll mul = 1;
					for(int t = 30; t >= 0; t--)
					{
						if (k & (1<<t))
						{
							mul *= ((t < i) ? 1 : ((top_a & (1<<t)) ? 1 : 0));
							mul *= ((t < j) ? 1 : ((top_b & (1<<t)) ? 1 : 0));
							continue;
						}
						//dbg("i = %d, j = %d, t = %d, mul = %lld, x1 = %d, x2 = %d\n", i, j, t, mul, 
							//((t < i) ? 1 : ((top_a & (1<<t)) ? 1 : 0)),
							//((t < j) ? 1 : ((top_b & (1<<t)) ? 1 : 0)));

						ans += mul 
							* ((t < i) ? 1 : ((top_a & (1<<t)) ? 1 : 0))
							* ((t < j) ? 1 : ((top_b & (1<<t)) ? 1 : 0)) 
							* (1LL << std::min(t, i))
							* (1LL << std::min(t, j));
						int a_0 = t < i ? 1 : ((top_a & (1<<t)) ? 0 : 1);
						int a_1 = t < i ? 1 : ((top_a & (1<<t)) ? 1 : 0);
						int b_0 = t < j ? 1 : ((top_b & (1<<t)) ? 0 : 1);
						int b_1 = t < j ? 1 : ((top_b & (1<<t)) ? 1 : 0);
						//dbg("%d %d %d %d\n", a_0, a_1, b_0, b_1);
						mul *= (a_0 * b_0 + a_0 * b_1 + a_1 * b_0);
					}
				}
			}
	printf("%lld\n", a * 1LL * b - ans);
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		solve(i);

	return 0;
}
