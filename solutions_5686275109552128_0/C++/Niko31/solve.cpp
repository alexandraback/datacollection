#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cout << "Case #" << tt << ": ";
		int n;
		cin >> n;
		vector<int> a(n);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			ans = max(a[i], ans);
		}
		int l = 0, r = ans;
		while (l + 1 < r) {
			int m = (l + r) / 2;
			bool ok = false;
			for (int part = 1; part <= m; part++) {
				int spec = 0;
				for (int i = 0; i < n; i++)
					spec += ((a[i] + part - 1) / part) - 1;
				if (spec + part <= m) {
					ok = true;
					break;
				}
			}
			ok ? (r = m) : (l = m);
		}
		ans = r;
		cout << ans << endl;
	}
}