#include <ctime>
#include <queue>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <numeric>
#include <deque>
#include <list>
#include <memory>
#include <memory.h>

using namespace std;

#define SZ(a) (int)(a).size()
#define FOR(i, a, b) for(int i=(a), _b(b); i<_b; ++i)
#define FORD(i, a, b) for(int i=(a)-1, _b(b); i>=_b; --i)
#define FIND(a, b) ((a).find(b)!=(a).end())
#define FILL(a, b) memset(a, b, sizeof(a))
#define SQR(a) ((a)*(a))

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

const int mod = 1000000009;

int ADD(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int SUB(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
int MUL(LL a, LL b) { return a*b%mod; }
int POW(int a, int b)
{
	if (!b) return 1;
	int t = POW(a, b >> 1);
	t = MUL(t, t);
	if (b & 1) t = MUL(t, a);
	return t;
}
int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }

double beginTime;

int a[330], dd[10];

int main()
{
#ifdef ALMAG_LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#endif

	int tc; scanf("%d", &tc);
	int cs = 0;
	while (tc --> 0)
	{
		int c, d, v; scanf("%d %d %d", &c, &d, &v);
		FOR(i, 0, d) scanf("%d", dd + i); sort(dd, dd + d);
		FILL(a, 0); a[0] = 1;

		FOR(i, 0, d)
		{
			FORD(j, v + 1, 0)
			{
				if (a[j]) a[j + dd[i]] = 1;
			}
		}

		int res = 0;
		FOR(i, 1, v + 1)
		{
			if (!a[i])
			{
				res++;
				FORD(j, v + 1, 0)
				{
					if (a[j]) a[j + i] = 1;
				}
			}
		}

		printf("Case #%d: %d\n", ++cs, res);
	}

	return 0;
}