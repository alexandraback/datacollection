#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (int)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

string l[20];
string r[20];
unordered_set<string> m1, m2;

int main() {
    inp("input.txt");
    out("output.txt");
    int t, tt;
    must;
    cin >> t;
    for(tt = 1; tt <= t; tt++) {
		cerr << tt << "\n";
		int n, i, j, mask;
		cin >> n;
		for(i = 0; i < n; i++) {
			cin >> l[i] >> r[i];
		}
		int res = 0;
		for(mask = 0; mask < (1 << n); mask++) {
			m1.clear();
			m2.clear();
			int ans = n;
			for(j = 0; j < n; j++)
				if((mask >> j) & 1) {
					ans--;
					m1.insert(l[j]);
					m2.insert(r[j]);
				}
			for(j = 0; j < n && ans; j++)
				if(m1.find(l[j]) == m1.end() || m2.find(r[j]) == m2.end())
					ans = 0;
			res = max(ans, res);
		}
		cout << "Case #" << tt << ": " << res << "\n";
    }
    return 0;
}
