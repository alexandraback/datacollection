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

const double eps = 1e-9;

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
		vector <int> s(n);
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &s[i]);
			sum += s[i];
		}
		printf("Case #%d:", ii);
		for (int i = 0; i < n; ++i)
		{
			double left = 0;
			double right = 1;
			for (int it = 0; it < 90; ++it)
			{
				double q = (left + right) / 2;
				double target = s[i] + sum * q;
				double lost = sum * (1 - q);
				for (int j = 0; j < n; ++j)
				{
					if (j == i)
						continue;
					if (s[j] > target)
						continue;
					lost -= target - s[j];
				}
				if (lost < -eps)
					right = q;
				else
				    left = q;
			}
			printf(" %.10lf", left * 100);
		}
		printf("\n");
	}

	return 0;
}
