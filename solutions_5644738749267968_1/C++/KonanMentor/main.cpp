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

li war (set <double> a, set <double> b)
{
	li res = 0;
	while (!a.empty())
	{
		set<double>::iterator i = b.lower_bound(*a.begin());
		a.erase(a.begin());

		if (i == b.end())
		{
			res ++;
			b.erase(b.begin());
		}
		else
		{
			b.erase(i);
		}
	}

	return res;
}

li deceitfulWar (set <double> a, set <double> b)
{
	li res = 0;
	while (!a.empty())
	{
		if (*a.begin() > *b.begin())
		{
			res ++;
			b.erase(b.begin());
		}
		else
		{
			b.erase(--b.end());
		}
		a.erase(a.begin());
	}

	return res;
}

void solve ()
{
	li tests;
	scanf("%ld", &tests);

	for (li t = 1; t <= tests; ++ t)
	{
		li n;
		scanf("%ld", &n);
		set <double> a, b;
		for (li i = 0; i < n; ++ i)
		{
			double x;
			scanf("%lf", &x);
			a.insert(x);
		}

		for (li i = 0; i < n; ++ i)
		{
			double x;
			scanf("%lf", &x);
			b.insert(x);
		}

		printf("Case #%ld: %ld %ld\n", t, deceitfulWar(a, b), war(a, b));
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
