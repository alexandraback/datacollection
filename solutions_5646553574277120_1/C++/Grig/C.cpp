#include <functional>
#include <algorithm>
#include <strstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(0);
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		int c, n;
		ll v;
		cin >> c >> n >> v;
		vector<ll> a(n);
		for (ll& x : a)
			cin >> x;
		sort(begin(a), end(a));
		ll cur = 0;
		int i = 0, ans = 0;

		while (cur < v)
		{
			if (i < n && a[i] <= cur + 1)
			{
				cur += a[i++] * c;
			}
			else
			{
				++ans;
				cur += (cur + 1) * c;
			}
		}
		cout << "Case #" << t << ": " << ans << endl;
	}

	return 0;
}