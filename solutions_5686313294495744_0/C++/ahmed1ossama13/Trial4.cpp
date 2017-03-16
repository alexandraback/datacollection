#include <bits/stdc++.h>
using namespace std;

set<string> S1, S2;
vector<string> V1, V2;
set<pair<string, string> > M;

int main() {
	ios::sync_with_stdio(false);
	freopen("/home/ahmed/Desktop/GCJ_1B/C/C-small-attempt2.in", "r", stdin);
	freopen("/home/ahmed/Desktop/GCJ_1B/C/C-small-attempt2.out", "w", stdout);
	int t; cin >> t;
	int id = 1;
	while (t--) {
		int n; cin >> n;
		V1.clear(); V2.clear();
		S1.clear(); S2.clear(); M.clear();
		for (int i = 0; i < n; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			V1.push_back(s1);
			V2.push_back(s2);
			S1.insert(s1);
			S2.insert(s2);
			M.insert(make_pair(s1, s2));
		}
		int ans = n + 1;
		for (int msk = 0; msk < (1 << n); msk++) {
			if (__builtin_popcount(msk) >= ans)
				continue;
			set<string> D1 = S1, D2 = S2;
			for (int i = 0; i < n; i++)
				if (msk & (1 << i)) {
					if (D1.find(V1[i]) != D1.end())
						D1.erase(V1[i]);
					if (D2.find(V2[i]) != D2.end())
						D2.erase(V2[i]);
				}
			if (D1.empty() && D2.empty())
				ans = min(ans, int(__builtin_popcount(msk)));
		}
		ans = n - ans;
		cout << "Case #" << (id++) << ": " << ans << endl;
	}
	return 0;
}
