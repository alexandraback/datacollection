#include <cstdio>
#include <string>
#include <cmath>
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
		double c, f, x;
		scanf("%lf%lf%lf", &c, &f, &x);
		int k = max(0, (int)ceil(x / c - 2.0 / f - 1.0 - 1e-9));
		double res = 0;
		for (int i = 0; i < k; ++i)
			res += c / (2.0 + f * i);
		res += x / (2.0 + f * k);
		printf("%.15lf\n", res);
	}

	return 0;
}
