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

double eps = 1e-9;

LL calcCollisions(double t1, int s1, double t2, int s2)
{
	if (t1 > t2)
	{
		swap(t1, t2);
		swap(s1, s2);
	}
	double nt = (360 - s2) / 360.0*t2;
	double dist = 360 *nt/t1;
	dist += s1;
	dist /= 360;
	LL ans = (LL)(dist + eps);
	if (s1 >= s2)
		ans--;
	return ans;
}
vector<int> vals;
vector<int> pos;

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
	FOR(testNumber, 1, tests + 1)
	{
		int n;
		scanf("%d", &n);
		vals.clear();
		pos.clear();
		FOR(i, 0, n)
		{
			int h, d, m;
			scanf("%d%d%d", &d, &h, &m);
			FOR(j, 0, h)
			{
				vals.push_back(m + j);
				pos.push_back(d);
			}
		}
		int res = (int)pos.size() - 1;
		FOR(i, 0, pos.size())
		{
			LL now = 0;
			FOR(j, 0, pos.size())
			{
				if (j == i)
					continue;
				now += calcCollisions(vals[i], pos[i], vals[j], pos[j]);
				if (now >= res)
					break;
			}
			res = MIN(res, now);
		}
		printf("Case #%d: %d\n", testNumber, res);
		fprintf(stderr, "Case #%d done\n", testNumber);
	}

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}