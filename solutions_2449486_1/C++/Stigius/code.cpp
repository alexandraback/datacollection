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

int ar[200][200];
int maxx[200], maxy[200];

void solve(int test_case)
{
	printf("Case #%d: ", test_case);
	int n,m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &ar[i][j]);
	for(int i = 0; i < n; i++)
	{
		maxx[i] = 0;
		for(int j = 0; j < m; j++)
			maxx[i] = std::max(maxx[i], ar[i][j]);
	}
	for(int j = 0; j < m; j++)
	{
		maxy[j] = 0;
		for(int i = 0; i < n; i++)
			maxy[j] = std::max(maxy[j], ar[i][j]);
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if (ar[i][j] < maxx[i] && ar[i][j] < maxy[j])
			{
				printf("NO\n");
				return;
			}

	printf("YES\n");
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		solve(i);

	return 0;
}
