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

bool f(int q, int n, vector <int> a, vector <int> b)
{
	const int INF = 100000;
	int stars = 0;
	while (stars < 2 * n)
	{
		int i = 0;
		while (i < n && (a[i] == INF || b[i] > stars))
			++i;
		if (i < n)
		{
			a[i] = INF;
			b[i] = INF;
			stars += 2;
			continue;
		}
		i = 0;
		while (i < n && (a[i] != INF || b[i] > stars))
			++i;
		if (i < n)
		{
			b[i] = INF;
			stars++;
			continue;
		}
		i = 0;
		while (i < n && (q == 0 || a[i] > stars))
			++i;
		if (i < n)
		{
			a[i] = INF;
			--q;
			++stars;
			continue;
		}
		return false;
	}
	return true;
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
		printf("Case #%d: ", ii);
		int n;
		scanf("%d", &n);
		vector <int> a(n), b(n);
		for (int i = 0; i < n; ++i)
			scanf("%d %d", &a[i], &b[i]);

		for (int i = 0; i < n; ++i)
			for (int j = 1; j < n; ++j)
			{
				if (b[j - 1] < b[j])
				{
					swap(a[j - 1], a[j]);
					swap(b[j - 1], b[j]);
				}
			}

		int l = 0;
		int r = n;
		while (l < r)
		{
			int q = (l + r) / 2;
			if (f(q, n, a, b))
				r = q;
			else
				l = q + 1;
		}
		if (!f(l, n, a, b))
			printf("Too Bad\n");
		else
			printf("%d\n", n + l);
	}

	return 0;
}
