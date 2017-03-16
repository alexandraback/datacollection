#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstdarg>

#define clr(a) memset(a, 0, sizeof(a))
#define fill(a, b) memset(a b, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;

using namespace std;

#define DBG2 1

void dbg(const char * fmt, ...)
{
#ifdef DBG1
#if DBG2
	FILE* file = stderr;
	va_list args;
	va_start(args, fmt);
	vfprintf(file, fmt, args);
	va_end(args);

	fflush(file);
#endif
#endif
}

int solve1(const vector <double> & a, const vector <double> & b)
{
	int n = int(a.size());
	vector < vector <int> > dp(n, vector <int>(n, -1));
	for (int len = 1; len <= n; ++len)
		for (int L = 0, R = len - 1; R < n; ++L, ++R)
		{
			int & res = dp[L][R];
			if (len == 1)
			{
				res = (a[n - 1] > b[L]) ? 1 : 0;
			}
			else
			{
				double A = a[n - len];
				res = 0;
				if (A > b[L])
					res = max(res, 1 + dp[L + 1][R]);
				if (A < b[R])
					res = max(res, dp[L][R - 1]);
			}
		}
	return dp[0][n - 1];
}

int solve2(const vector <double> & a, const vector <double> & b)
{
	int n = int(a.size());
	int res = 0;
	set<double> B;
	for (int i = 0; i < n; ++i)
		B.insert(b[i]);
	for (int i = 0; i < n; ++i)
	{
		set<double>::iterator it = B.lower_bound(a[i]);
		if (it == B.end())
			++res;
		else
			B.erase(it);
	}
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
		int n;
		scanf("%d", &n);
		vector <double> a(n), b(n);
		for (int i = 0; i < n; ++i)
			scanf("%lf", &a[i]);
		for (int i = 0; i < n; ++i)
			scanf("%lf", &b[i]);
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		printf("%d %d\n", solve1(a, b), solve2(a, b));
	}

	return 0;
}
