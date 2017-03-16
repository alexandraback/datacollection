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
	for (int ii = 0; ii < tt; ++ii)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		int pow10 = 1;
		while (pow10 <= b)
			pow10 *= 10;
		int res = 0;
		for (int i = a; i <= b; ++i)
		{
			int j = i;
			do {
				j = (pow10 * (j % 10) + j) / 10;
				if (i < j && j <= b)
					++res;
			} while (j != i);
		}
		printf("Case #%d: %d\n", ii + 1, res);
	}

	return 0;
}
