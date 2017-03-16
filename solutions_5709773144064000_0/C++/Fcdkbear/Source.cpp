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
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned


void solve(double c, double f, double x)
{
	double rate = 2;
	double res = x/rate;
	double t = 0;
	int it = 0;
	while (1)
	{
		t += c / rate;
		rate += f;
		double res1 = t + x / rate;
		if (res1 > res)
		{
			printf("%.7lf\n", res);
			return;
		}
		res = res1;
	}
}

int main()
{
#ifdef Fcdkbear
	freopen("in.txt", "r", stdin);
	freopen("out.txt","w",stdout);
	double beg = clock();
#else
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	FOR(it, 0, t)
	{
		double c, f, x;
		scanf("%lf%lf%lf", &c, &f, &x);
		printf("Case #%d: ", it + 1);
		solve(c, f, x);
		fprintf(stderr, "Case #%d done\n", it+1);
	}

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
}