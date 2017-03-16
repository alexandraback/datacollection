#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb emplace_back

using namespace std;

typedef long long ll;

const int maxn = 3;

int ab[maxn][maxn], bc[maxn][maxn], ac[maxn][maxn], k;
int a, b, c;
vector< tuple<int, int, int> > cur, opt;

void rec(int na, int nb, int nc, int d) {
	if (nc == c) {
		rec(na, nb + 1, 0, d);
		return;
	}
	if (nb == b) {
		rec(na + 1, 0, nc, d);
		return;
	}
	if (na == a) {
		if (cur.size() > opt.size()) {
			opt = cur;
		}
		return;
	}
	if (ab[na][nb] < k && ac[na][nc] < k && bc[nb][nc] < k) {
		ab[na][nb]++;
		ac[na][nc]++;
		bc[nb][nc]++;
		cur.emplace_back(na, nb, nc);
		rec(na, nb, nc + 1, d + 1);
		cur.pop_back();
		ab[na][nb]--;
		ac[na][nc]--;
		bc[nb][nc]--;
	}
	rec(na, nb, nc + 1, d);
}

void solve() {
	cin >> a >> b >> c >> k;
	opt.clear();
	rec(0, 0, 0, 0);
	cout << opt.size() << '\n';
	for (size_t i = 0; i < opt.size(); ++i) {
		cout << get<0>(opt[i]) + 1 << " " << get<1>(opt[i]) + 1
			   << " " << get<2>(opt[i]) + 1 << '\n';
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cout << "Case #" << i + 1 << ": ";
		solve();
	}
  return 0;
}
