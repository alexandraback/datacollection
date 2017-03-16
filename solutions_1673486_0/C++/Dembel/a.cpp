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
		int a, b;
		scanf("%d %d", &a, &b);
		vector <double> p(a);
		vector <double> all(a);
		for (int i = 0; i < a; ++i)
		{
			scanf("%lf", &p[i]);
			all[i] = (i == 0) ? p[i] : all[i - 1] * p[i];
		}

	    double ans = 1 + b + 1;
		for (int i = 0; i < a; ++i)
		{
			double prob = all[a - i - 1];
			ans = min(ans, prob * (2 * i + (b - a) + 1) + (1 - prob) * (2 * i + (b - a) + 1 + b + 1));
        }
        printf("Case #%d: %.10lf\n", ii, ans);
	}

	return 0;
}
