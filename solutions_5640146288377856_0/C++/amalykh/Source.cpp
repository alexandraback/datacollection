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
		int r, c;
		cin >> r >> c;
		int w;
		cin >> w;

		int ans = 1;
		int pos = w - 1;
		while (pos + w < c)
		{
			ans++;
			pos += w;
		}

		if (pos == c - 1)
			ans += w - 1;
		else
			ans += w;

		printf("Case #%d: %d\n", q + 1, ans);
	}

	return 0;
}