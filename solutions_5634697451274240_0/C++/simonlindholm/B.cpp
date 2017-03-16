#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

void solve() {
	string s;
	cin >> s;
	char last = s[0];
	int res = 0;
	for (char c : s + "+") {
		if (c != last) res++;
		last = c;
	}
	cout << res << endl;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	rep(i,0,N) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
}
