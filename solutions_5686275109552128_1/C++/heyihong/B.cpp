#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int test_case, tc, d;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; ++tc) {
		cin >> d;
		vector<int> diner;
		int maxp = 0;
		for (int i = 0; i != d; ++i) { 
			int p;
			cin >> p;
			diner.push_back(p);
			maxp = max(maxp, p);
		}
		int ans = maxp;
		for (int ep = 1; ep <= maxp; ++ep) {
			int cnt = ep;
			for (int p : diner) {
				for (; p > ep; p -= ep)
					++cnt;
			}
			ans = min(ans, cnt);
		}
		cout << "Case #" << tc << ": " << ans << endl;
	}
	return 0;
}
