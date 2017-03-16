#include <bits/stdtr1c++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef complex<ld> pt;

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    for (int ca = 1; ca <= t; ca++) {
        cout << "Case #" << ca << ": ";
		
		int n; cin >> n;
		vector<pair<string, string>> words(n);
		for (int i = 0; i < n; i++) {
			cin >> words[i].first >> words[i].second;
		}
		
		int ans = 0;
		for (int bs = 0; bs < (1<<n); bs++) {
			set<string> a[2], b[2];
			for (int i = 0; i < n; i++) {
				if (bs & (1<<i)) {
					a[0].insert(words[i].first);
					a[1].insert(words[i].second);
				} else {
					b[0].insert(words[i].first);
					b[1].insert(words[i].second);
				}
			}
			
			bool subset = true;
			for (int k = 0; k < 2; k++) {
				for (const string& s : a[k]) {
					if (!b[k].count(s)) {
						subset = false;
						break;
					}
				}
			}
			if (subset) {
				ans = max(ans, __builtin_popcount(bs));
			}
		}
		cout << ans << endl;
    }
	return 0;
}