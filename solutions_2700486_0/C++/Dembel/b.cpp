#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <cstdarg>

#pragma comment(linker, "/STACK:64000000")

#define DBG2 1

void dbg(const char * fmt, ...)
{
#ifdef DBG1
#if DBG2
	va_list args;
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);

	fflush(stderr);
#endif
#endif
}

using namespace std;

#define clr(a) memset(a, 0, sizeof(a))
#define fill(a, b) memset(a, b, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;

int getCount(int h)
{
	return (h + 2) * (h + 1) / 2;
}

int getCount(int x, int y)
{
	if (x == 0)
		return getCount(y);
	else
		return getCount(x + y - 2);
}

double dp[4000][4000];

double calcDp(int h, int n, int k)
{
	dbg("calc h = %d, n = %d, k = %d\n", h, n, k);
	for (int i = 0; i <= h; ++i)
		for (int j = 0; j <= h; ++j)
			dp[i][j] = 0.0;
	dp[0][0] = 1.0;
	for (int i = 0; i <= n && i <= h; ++i)
		for (int j = 0; i + j <= n && j <= h; ++j)
		{
			dbg("dp[%d][%d] = %.10lf\n", i, j, dp[i][j]);
			if (i == h)
				dp[i][j + 1] += dp[i][j];
			else if (j == h)
				dp[i + 1][j] += dp[i][j];
			else
			{
				dp[i + 1][j] += dp[i][j] / 2;
				dp[i][j + 1] += dp[i][j] / 2;
			}
		}
	double res = 0;
	for (int i = k; i <= h; ++i)
		if (0 <= n - i && n - i <= h)
			res += dp[i][n - i];
	return res;
}         

int main()
{
#ifdef DBG1
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	freopen(".err", "w", stderr);
#endif

	int tt;
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		printf("Case #%d: ", ii);
		int n, x, y;
		scanf("%d%d%d", &n, &x, &y);
		if (x < 0)
			x = -x;
	    if (x == 0)
	    {
			int cnt = getCount(x, y);
			printf("%.10lf\n", cnt <= n ? 1.0 : 0.0);
		}
		else
		{
			int cnt = getCount(x, y);
			if (n <= cnt)
				printf("%.10lf\n", 0);
			else
			{
				n -= cnt;
				if (n >= (x + y) + y + 1)
					printf("%.10lf\n", 1);
				else
				{
					printf("%.10lf\n", calcDp(x + y, n, y + 1));
					continue;

					cnt = y + 1;
					double prob = 0;
					double curC = 1;
					int lostPow2 = n;
					for (int i = n; i >= cnt; --i)
					{
						if (i < x + y)
							prob += curC;
						while (prob >= 1 && curC >= 1 && lostPow2)
						{
							prob /= 2.0;
							curC /= 2.0;
							lostPow2--;
						}
						curC = curC * i / (n - i + 1);
					}
					while (lostPow2)
					{
						prob /= 2;
						--lostPow2;
					}

					double prob2 = 0;
					curC = 1;
					lostPow2 = x + y;
					for (int i = x + y; i <= n - 1; ++i)
					{
						if (i == n - 1)
							prob2 += curC;
						while (prob2 >= 1 && curC >= 1 && lostPow2)
						{
							prob2 /= 2.0;
							curC /= 2.0;
							lostPow2--;
						}
						curC = curC * (i + 1) / (i + 1 - (y + x)) / 2;
					}
					while (lostPow2)
					{
						prob2 /= 2;
						--lostPow2;
					}

					dbg("%.10lf %.10lf\n", prob, prob2);
					printf("%.10lf\n", prob + prob2);
				}
			}			
		}
	}

	return 0;
}