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


int ar[1000000];

void solve(int test_case)
{
	printf("Case #%d: ", test_case);
	ll cur;
	int n;
	scanf("%lld%d", &cur, &n);
	int ans = n;
	for(int i = 0; i < n; i++)
		scanf("%d", &ar[i]);
	std::sort(ar, ar+n);
	int curact = 0;
	bool good = true;
	for(int i = 0; good && i < n; i++)
	{
		ans = std::min(ans, curact + n - i);
		while(ar[i] >= cur)
		{
			if (cur == 1)
			{
				good = false;
				break;
			}
			cur = 2 * cur - 1;
			curact ++;
		}
		cur += ar[i];
	}
	if(good)
		ans = std::min(ans, curact);

	printf("%d\n", ans);
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		solve(i);

	return 0;
}
