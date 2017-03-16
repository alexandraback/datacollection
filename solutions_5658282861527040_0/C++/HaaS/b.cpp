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

int find (int x, int y, int k, int l) {
	if (l == -1) return 0;
	if (k & (1 << l))
		if (x <= (1 << l) || y <= (1 << l))
			return x * y;
		else
			return (1 << l) * (x + y - (1 << l)) + find (x - (1 << l), y - (1 << l), k, l - 1);
	int res = 0;
	if (y > (1 << l)) res += find (min (x, (1ll << l)), y - (1ll << l), k, l - 1);
	if (x > (1 << l)) res += find (x - (1ll << l), min (y, (1ll << l)), k, l - 1);
	res += find (min (x, (1ll << l)), min (y, (1ll << l)), k, l - 1);
	return res;
}

int solve() {
	int a, b, k;
	cin >> a >> b >> k;
	return find (a, b, k, 30);
}

main() {
	ios::sync_with_stdio (false);

	int tests; cin >> tests;
	for (int o = 1; o <= tests; o++) {
		int res = solve();
		cout << "Case #" << o << ": " << res << endl; 
	}

	return 0;
}
