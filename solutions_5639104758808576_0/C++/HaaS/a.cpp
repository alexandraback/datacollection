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
	string s; cin >> s >> s;
	int last = 0, ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (last <= i && s[i] == '0') s[i]++, ans++;
		last += s[i] - '0';
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
