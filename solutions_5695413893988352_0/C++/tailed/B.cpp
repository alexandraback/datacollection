#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<int(n); ++i)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
typedef long long ll;


int TC;
bool check(int x, string a) {
	for(int i=sz(a)-1; i>=0; i--) {
		if (a[i] != '?' && (a[i] - '0') != x % 10) return false;
		x = x / 10;
	}
	return true;
}
void output(int x, int n) {
	vector<int> as;
	rep(i, n) {
		as.push_back(x % 10);
		x /= 10;
	}
	reverse(all(as));
	for(auto i : as) cout << i;
}
void solve() {
	string a, b;
	cin >> a >> b;
	int n = sz(a);

	int T=1;
	rep(i, n) T *= 10;
	tuple<int, int, int> ans(1<<29, 1<<29, 1<<29);
	rep(i, T) if (check(i, a)) rep(j, T) if (check(j, b)) {
		auto res = make_tuple(abs(i-j), i, j);
		ans = min(ans, res);
	}
	output(get<1>(ans), n);
	cout << ' ';
	output(get<2>(ans), n);
	cout << endl;
}
int main() {
	int T; cin >> T;
	for(TC=1; TC<=T; TC++) {
		cout << "Case #" << TC << ": ";
		solve();
	}
}

