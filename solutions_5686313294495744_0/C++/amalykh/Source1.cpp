#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:134217728")
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <map>
#include <sstream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <utility>
#include <ctime>
#include <string>

using namespace std;

typedef long long ll;

#define ZERO(x) memset((x), 0, sizeof(x))
#define NEGATE(x) memset((x), 255, sizeof(x))
#define mp make_pair
#define mt(a, b, c) mp(a, mp(b, c))

int main()
{
#ifdef XXX
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int te;
	cin >> te;
	for (int w = 0; w < te; w++)
	{
		int n;
		cin >> n;
		vector<pair<string, string>> v(n);
		for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
		int ans = 0;
		for (int mask = 0; mask < (1 << n); mask++)
		{
			int cur = 0;
			set<string> S1, S2;
			for (int i = 0; i < n; i++)
			{
				if ((mask >> i) & 1)
				{
					S1.insert(v[i].first);
					S2.insert(v[i].second);
				}
				else
					cur++;
			}

			bool ok = 1;
			for (int i = 0; i < n; i++)
			{
				if (((mask >> i) & 1) == 0)
				{
					if (!S1.count(v[i].first) || !S2.count(v[i].second))
						ok = 0;
				}
			}
			if (ok) ans = max(ans, cur);
		}

		printf("Case #%d: %d\n", w + 1, ans);

	}

	return 0;
}