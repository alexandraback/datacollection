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


vector<int> a, b;
vector<int> was;
int solve2()
{
	int res = 0;
	was.clear();
	was.resize(a.size(), 0);
	FOR(i, 0, a.size())
	{
		bool f = true;
		FOR(j, 0, b.size())
		{
			if ((b[j] > a[i]) && (was[j] == 0))
			{
				was[j] = 1;
				f = false;
				break;
			}
		}
		res += f;
	}
	return res;
}

int solve1()
{
	int res = 0;
	was.clear();
	was.resize(a.size(), 0);
	FOR(i, 0, a.size())
	{
		bool f = false;
		FOR(j, 0, b.size())
		{
			if ((b[j] < a[i]) && (was[j] == 0))
			{
				was[j] = 1;
				f = true;
				break;
			}
		}
		res += f;
	}
	return res;
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
		int n;
		scanf("%d", &n);
		a.clear();
		b.clear();
		a.resize(n);
		b.resize(n);
		FOR(i, 0, n)
		{
			int v1, v2;
			scanf("%d.%d", &v1, &v2);
			a[i] = v1 * 100000 + v2;
		}
		FOR(i, 0, n)
		{
			int v1, v2;
			scanf("%d.%d", &v1, &v2);
			b[i] = v1 * 100000 + v2;
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int res1 = solve1();
		int res2 = solve2();
		printf("Case #%d: %d %d\n", it + 1, res1, res2);
	}

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
}