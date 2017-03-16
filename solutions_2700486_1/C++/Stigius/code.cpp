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


double dp[10000][10000];

void solve(int test_case)
{
	printf("Case #%d: ", test_case);
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	if (x < 0) x = -x;

	int current_group = 1;
	int total_sum = 0;
	int levels = 0;

	while(total_sum + current_group <= n)
	{
		levels++;
		total_sum += current_group;
		current_group += 4;		
	}
	if (levels > (x + y) / 2)
	{
		//dbg("Covered by level\n");
		printf("%.10lf\n", 1.0);
		return;
	}
	if (levels <= (x + y) / 2 - 1)
	{
		//dbg("Not enough levels\n");
		printf("%.10lf\n", 0.);
		return;
	}
	n -= total_sum;
	int m = current_group / 2 + 1;
	if (y >= m - 1)
	{
		//dbg("Too high\n");
		printf("%.10lf\n", 0.);
		return;
	}

	for(int i = 0; i <= m; i++)
		for(int j = 0; j <= m; j++)
			dp[i][j] = 0;
	dp[0][0] = 1;

	for(int i = 0; i <= m; i++)
		for(int j = 0; j <= m && i + j < n; j++)
		{
			if (i < m-1 && j < m-1)
			{
				dp[i+1][j] += dp[i][j] / 2;
				dp[i][j+1] += dp[i][j] / 2;
			}
			else if (i < m-1)
			{
				dp[i+1][j] += dp[i][j];
			}
			else if (j < m-1)
			{
				dp[i][j+1] += dp[i][j];
			}
		}
	double ans = 0;
	for(int i = y + 1; i <= m; i++)
		ans += dp[i][n-i];
	//dbg("Dp value\n");
	printf("%.10lf\n", ans);
}


int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		solve(i);

	return 0;
}
