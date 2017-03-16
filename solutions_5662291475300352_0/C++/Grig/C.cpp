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

	freopen("X.in", "r", stdin);
	freopen("X.out", "w", stdout);

	int t;
	cin >> t;
	for (int tn = 1; tn <= t; ++tn)
	{
		int n;
		vector<pair<ll, ll>> v;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			ll d, h, m;
			cin >> d >> h >> m;
			while (h--)
			{
				v.push_back(make_pair(d, m));
				++m;
			}
		}
		sort(v.begin(), v.end());
		int ans;
		if (v.size() < 2)
			ans = 0;
		else
		{
			const double eps = 1e-9;
			if (v[0].second < v[1].second)
			{
				double d0 = double(360 - v[1].first + v[0].first) / (v[1].second - v[0].second);
				double d1 = double(360 - v[0].first) / v[0].second;
				if (d1 < d0 - eps)
					ans = 0;
				else
					ans = 1;
			}
			else
			{
				double d0 = double(v[1].first - v[0].first + 360) / (v[0].second - v[1].second);
				double d1 = double(360 - v[1].first) / v[1].second;
				if (d1 < d0 - eps)
					ans = 0;
				else
					ans = 1;
			}
		}

		cout << "Case #" << tn << ": " << ans << endl;
	}

	return 0;
}