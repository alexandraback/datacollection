#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#include <functional>
#include <climits>
#include <cassert>
#include <list>

#define mp make_pair
#define mt(a, b, c) mp(a, mp(b, c))
#define ABS(a) (((a) > 0) ? (a) : (-(a)))
#define ZERO(x) memset((x), 0, sizeof(x))
#define NEGATE(x) memset((x), 255, sizeof(x))

using namespace std;
typedef long long ll;

set<ll> ds;

int main()
{
#ifdef XXX
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tests;
	cin >> tests;
	for (int q = 0; q < tests; q++)
	{
		ll r = 0;
		ll c, d, v;
		cin >> c >> d >> v;

		ds.clear();

		for (int i = 0; i < d; i++)
		{
			ll x;
			cin >> x;
			ds.insert(x);
		}

		int ans = 0;
		while (r < v)
		{
			if (!ds.empty())
			{
				if ((*ds.begin()) <= r + 1)
				{
					r += (*ds.begin()) * c;
					ds.erase(ds.begin());
					continue;
				}
			}
			r += (r + 1) * c;
			ans++;
		}

		printf("Case #%d: %d\n", q + 1, ans);
	}

	return 0;
}