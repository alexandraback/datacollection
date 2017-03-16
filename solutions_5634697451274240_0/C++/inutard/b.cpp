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
		string s; cin >> s;
		int ans = 0;
		for (int i = 0; i < int(s.size())-1; i++) {
			if (s[i] != s[i+1]) ans++;
		}
        cout << "Case #" << ca << ": " << ans + (s.back() == '-') << endl;
    }
	return 0;
}