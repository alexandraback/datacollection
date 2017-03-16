#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <list>
#include <set>
#include <queue>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

typedef long long lli;
typedef long li;

const lli INFLL = LONG_LONG_MAX;
const li INF = LONG_MAX;

double delay (double x, double r)
{
	if (x < 0) return 0.;
	return x / r;
}

void solve ()
{
	li tests;
	scanf("%ld", &tests);

	for (li t = 1; t <= tests; ++ t)
	{
		double c, f, x, s = 0, r = 2, time = 0;
		scanf("%lf %lf %lf", &c, &f, &x);

		for (;;)
		{
			double with = delay(c - s, r) + delay(x - (s > c ? s - c : 0), r + f), without = delay(x - s, r);
			if (with < without)
			{
				time += delay(c - s, r);
				s = s > c ? s - c : 0;
				r += f;
			}
			else
			{
				time += without;
				break;
			}
		}

		printf("Case #%ld: %.9lf\n", t, time);
	}
}

void init ()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int main()
{
	//init();
	solve();
	return 0;
}
