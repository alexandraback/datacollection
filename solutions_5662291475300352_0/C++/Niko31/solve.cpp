#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int tt = 1; tt <= t; tt++)
	{
		cout << "Case #" << tt << ": ";
		int m, n = 0;
		cin >> m;
		vector<pair<long long, long long> > a;
		for (int i = 0; i < m; i++) {
			int d, h, mm;
			cin >> d >> h >> mm;
			for (int j = 0; j < h; j++)
				a.push_back({d, mm + j});
		}
		n = a.size();

		int ans = n;
		for (int mask = 0; mask < (1 << n); mask++) {
			long long len = 0;
			for (int i = 0; i < n; i++)
				if ((1 << i) & mask) len = max(len, a[i].second * (360 - a[i].first));

			int cur = n - __builtin_popcount(mask);
			for (int i = 0; i < n; i++) {
				cur += (len - a[i].second * (360 - a[i].first)) / 360 / a[i].second;
			}
			ans = min(ans, (int)cur);	
		}

		cout << ans << endl;
	}
}