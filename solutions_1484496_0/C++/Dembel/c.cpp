#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

#include <cstdarg>

using namespace std;

#define DBG2 1

#define clr(a) memset(a, 0, sizeof(a))
#define fill(a, b) memset(a, b, sizeof(a))

void dbg(char * fmt, ...)
{
#ifdef DBG1
#if	DBG2
	FILE * file = stdout;

	va_list args;
	va_start(args, fmt);
	vfprintf(file, fmt, args);
	va_end(args);

	fflush(file);
#endif
#endif
}

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;

void print(int n, int mask, vector <int>& a)
{
	for (int i = 0; i < n; ++i)
		if (mask & (1 << i))
			printf("%d ", a[i]);
	printf("\n");
}

int main()
{
#ifdef DBG1
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif

	int tt;
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		int n;
		scanf("%d", &n);
		vector <int> a(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		vector <pii> sums;
		for (int i = 1; i < (1 << n); ++i)
		{
			int sum = 0;
			for (int j = 0; j < n; ++j)
				if ((1 << j) & i)
					sum += a[j];
			sums.push_back(pii(sum, i));
		}
		sort(sums.begin(), sums.end());
		int res;
		for (res = 1; res < int(sums.size()); ++res)
			if (sums[res - 1].first == sums[res].first)
				break;
		printf("Case #%d:\n", ii);
		if (res == (int)sums.size())
			printf("Impossible\n");
		else
		{
			print(n, sums[res - 1].second, a);
			print(n, sums[res].second, a);
		}
	}

	return 0;
}
