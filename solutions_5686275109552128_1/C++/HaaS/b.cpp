#include <bits/stdc++.h>

using namespace std;

#define int long long

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))

typedef long long ll;
typedef pair <int, int> pie;

void solve(stringstream &out) {
	int n;
	cin >> n;
	vector <int> a (n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int ans = *max_element (a.begin(), a.end());
	for (int lim = ans; lim >= 1; lim--) {
		int tmp = 0;
		for (int i = 0; i < n; i++)
			tmp += (a[i] + lim - 1) / lim - 1;
		ans = min (ans, tmp + lim);
	}
	out << ans;
}

main() {
	ios::sync_with_stdio (false);

	int tests; cin >> tests;
	for (int o = 1; o <= tests; o++) {
		stringstream out;
		solve(out);
		cout << "Case #" << o << ": " << out.str() << endl; 
		// clean your things!
	}

	return 0;
}
