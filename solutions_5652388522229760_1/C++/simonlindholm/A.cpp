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
	int N;
	cin >> N;
	if (N == 0) {
		cout << "INSOMNIA" << endl;
		return;
	}
	ll cur = 0;
	int count = 0;
	array<int, 10> have{};
	for (;;) {
		cur += N;
		ostringstream oss;
		oss << cur;
		string s = oss.str();
		for (char c : s) {
			int& a = have[c - '0'];
			if (a++ == 0)
				count++;
		}
		if (count == 10)
			break;
	}
	cout << cur << endl;
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
