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
#include <unordered_map>

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

int a, b, k;
LL dp[32][2][2][2];
LL r(int p, int f1, int f2, int f3)
{
	if (p < 0)
	{
		if ((f1) && (f2) && (f3))
			return 1;
		return 0;
	}
	if (dp[p][f1][f2][f3] != -1)
		return dp[p][f1][f2][f3];
	int b1 = ((a >> p) & 1);
	int b2 = ((b >> p) & 1);
	int b3 = ((k >> p) & 1);
	LL res = 0;
	FOR(i, 0, 2)
	{
		FOR(j, 0, 2)
		{
			if ((i > b1) && (f1 == 0))
				continue;
			if ((j > b2) && (f2 == 0))
				continue;
			int c = (i&j);
			if ((c > b3) && (f3 == 0))
				continue;
			int nf1 = f1;
			if (i < b1)
				nf1 = 1;
			int nf2 = f2;
			if (j < b2)
				nf2 = 1;
			int nf3 = f3;
			if (c < b3)
				nf3 = 1;
			res += r(p - 1, nf1, nf2, nf3);
		}
	}
	return dp[p][f1][f2][f3] = res;
}

int main()
{
#ifdef Fcdkbear
	freopen("in.txt", "r", stdin);
	freopen("out.txt","w",stdout);
	double beg = clock();
#else
	freopen("in.txt", "r", stdin);
	freopen("out.txt","w",stdout);
#endif

	int t;
	scanf("%d", &t);
	FOR(it, 1, t + 1)
	{
		cin >> a >> b >> k;
		MEMS(dp, -1);
		LL res = r(30, 0, 0, 0);
		printf("Case #%d: ", it);
		cout << res << endl;
	}

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
}