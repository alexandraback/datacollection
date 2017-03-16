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

bool w[60];

bool ok(int v)
{
	for (int i = 0; i <= v; i++)
	{
		if (!w[i]) return 0;
	}
	return 1;
}

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
		int c, d, v;
		cin >> c >> d >> v;
		ZERO(w);

		vector<int> a;

		for (int i = 0; i < d; i++)
		{
			int x;
			cin >> x;
			a.push_back(x);
		}

		w[0] = 1;

		for (int i = 0; i < a.size(); i++)
		{
			for (int j = v; j >= 0; j--)
			{
				if (j + a[i] >= 60) continue;
				if (!w[j]) continue;
				w[j + a[i]] = 1;
			}
		}

		int ans = 0;

		while (!ok(v))
		{
			ans++;
			int mn = 31;
			for (int i = 0; i <= v; i++)
			{
				if (!w[i])
				{
					mn = i;
					break;
				}
			}

			for (int i = v; i >= 0; i--)
			{
				if (!w[i]) continue;
				if (i + mn >= 60) continue;
				w[i + mn] = 1;
			}
		}

		printf("Case #%d: %d\n", q + 1, ans);
	}

	return 0;
}