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
		int a, n;
		scanf("%d%d", &a, &n);
		vector <int> v(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		sort(v.begin(), v.end());
		int res = n;
		if (a != 1)
		{
			int cur = 0;
			for (int i = 0; i < n; ++i)
			{
				while (a <= v[i])
				{
					a += a - 1;
					++cur;
				}
				a += v[i];
				res = min(res, cur + (n - i - 1));
			}
		}
		printf("Case #%d: %d\n", ii, res);
	}

	return 0;
}