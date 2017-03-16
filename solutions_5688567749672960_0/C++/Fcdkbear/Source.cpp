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

int rev(int x)
{
	int res = 0;
	while (x)
	{
		int v = x % 10;
		res = res * 10 + v;
		x /= 10;
	}
	return res;
}

int p[1000010];
int ans[1000010];

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

	p[0] = 1;
	ans[1] = 1;
	int l = 0, r = 0;
	while (l <= r)
	{
		int v = p[l++];
		int ne = v + 1;
		if ((ne <= 1000000) && (ans[ne] == 0))
		{
			ans[ne] = ans[v] + 1;
			r++;
			p[r] = ne;
		}
		ne = rev(v);
		if ((ne <= 1000000) && (ans[ne] == 0))
		{
			ans[ne] = ans[v] + 1;
			r++;
			p[r] = ne;
		}
	}
	int tests;
	scanf("%d", &tests);
	FOR(testNumber, 1, tests + 1)
	{
		int v;
		scanf("%d", &v);
		printf("Case #%d: %d\n", testNumber, ans[v]);
		fprintf(stderr, "Case #%d done\n", testNumber);
	}

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}