#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.1415926535897
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

int a[1010];

int main()
{
#ifdef Fcdkbear
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	double beg = clock();
#else
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int tests;
	scanf("%d", &tests);
	for (int it = 1; it <= tests; ++it)
	{
		int n;
		scanf("%d", &n);
		FOR(i, 0, n)
			scanf("%d", &a[i]);
		int l = 0, r = 1000;
		int ans = r;
		while (l <= r)
		{
			int m = (l + r) / 2;
			bool f = false;
			FOR(p, 0, m)
			{
				int have = 0;
				FOR(i, 0, n)
				{
					have += ((a[i] + m - p - 1) / (m - p)) - 1;
				}
				if (have <= p)
				{
					f = true;
					break;
				}
			}
			if (f)
			{
				ans = m;
				r = m - 1;
			}
			else
				l = m + 1;
		}
		printf("Case #%d: %d\n", it, ans);
	}

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}