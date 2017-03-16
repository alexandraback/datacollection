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

int calcCollisions(double t1, double s1, double t2)
{
	double val1 = (360 - s1)*t1 / 360;
	if (val1-eps>t2)
		return 1;
	double dist = 360 / t1*t2;
	dist += s1;
	dist /= 360;
	int ans = (int)(dist + eps);
	if (ans > 0)
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
		int res = 1000000000;
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
		if (pos.size() < 2)
		{
			printf("Case #%d: %d\n", testNumber, 0);
			continue;
		}
		if (vals[0] > vals[1])
		{
			swap(vals[0], vals[1]);
			swap(pos[0], pos[1]);
		}
		double t1 = vals[0] + (360 - pos[0]) / 360.0*vals[0];
		double t2 = (360 - pos[1]) / 360.0*vals[1];
		res = 0;
		if (t1 - eps <= t2)
			res = 1;
		printf("Case #%d: %d\n", testNumber, res);
		fprintf(stderr, "Case #%d done\n", testNumber);
	}

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}