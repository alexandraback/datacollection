#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <climits>
#include <cassert>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

#define ZERO(x) memset((x), 0, sizeof(x))
#define NEGATE(x) memset((x), 255, sizeof(x))

#define mp make_pair
#define mt(a, b, c) mp(a, mp(b, c))

typedef long long ll;
typedef pair<int, int> ii;


int main()
{
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T, r, c, w;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int ans = 0;
		cin >> r >> c >> w;

		int l = floor(c / w);
		ans = (r - 1) * l + l - 1;
		int k = c - (l - 1) * w;
		if (k == w)
			ans += w;
		else
			ans += w + 1;
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}

	return 0;
}