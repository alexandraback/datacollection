#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include <string>
#include <ctime>

using namespace std;

#define rep(x, y, z) for(int x = (y), end##x = (z); x < end##x; x++)
#define all(x) (x).begin(),(x).end()

#ifdef LOCAL_DEBUG

#define DebugPrint(...) fprintf(stderr, __VA_ARGS__);

#else

#define DebugPrint(...)

#endif

typedef long long ll;
typedef pair<int, int> pii;

void test(int testNum);
void init();

int main()
{
	//
#ifdef LOCAL_DEBUG

	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

#else

	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);

#endif

	clock_t cl = clock();

	init();

	int tc;
	scanf("%d", &tc);

	rep(i, 0, tc)
		test(i+1);

#ifdef LOCAL_DEBUG

	fprintf(stderr, "\nTime used: %lf\n", (clock() - cl) / (double)CLOCKS_PER_SEC);

#endif

	return 0;
}

void init()
{

}

int values[12000];

void test(int testNum)
{
	printf("Case #%d: ", testNum);
	
	int e, r, n;
	scanf("%d%d%d", &e, &r, &n);
	ll res = 0;

	if (r > e)
		r = e;

	rep(i, 0, n)
	{
		scanf("%d", values + i);
	}

	int curEn = e;
	int ub = e - r;
	rep(i, 0, n)
	{
		//if (curEn > ub)
		//{
		//	res += values[i] * ll(curEn - ub);
		//	curEn = ub;
		//}
		int foundVal = -1;
		int ce = e;
		rep(j, i + 1, n)
		{
			if (values[j] > values[i])
			{
				foundVal = j;
				break;
			}

			ce -= r;
			if (ce <= 0)
				break;
		}
		if (foundVal != -1)
		{
			int tb = e - r * (foundVal - i);
			tb = max(tb, 0);
			if (curEn > tb)
			{
				res += (curEn - tb) * (ll)values[i];
				curEn = tb;
			}
			curEn += r * (foundVal - i);
			i = foundVal - 1;
			curEn = min(curEn, e);
		}
		else
		{
			res += curEn * (ll)values[i];
			curEn = r;
		}
	}
	printf("%lld\n", res);
}