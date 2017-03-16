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
	int K, C, S;
	cin >> K >> C >> S;
	if (S * C < K) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	int at = 0;
	while (at < K) {
		ll r = 0;
		rep(i,0,C) {
			r *= K;
			r += min(at + i, K-1);
		}
		r++;
		cout << r << ' ';
		at += C;
	}
	cout << endl;
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
