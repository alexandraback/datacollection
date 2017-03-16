#include <bits/stdc++.h>
using namespace std;
#define M_PI        3.14159265358979323846

typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;

vector<int> poss;

pair<ll, pair<ll, ll>> res;

string a[2];

void brute(int len = 0) {
	if (len >= poss.size()) {
		ll code = atoll(a[0].data());
		ll jam = atoll(a[1].data());
		pair<ll, pair<ll, ll>> cres = { abs(code - jam), { code, jam } };
		res = min(res, cres);
		return;
	}
	for (char num = '0'; num <= '9'; num++) {
		a[poss[len] >> 6][poss[len] & 63] = num;
		brute(len + 1);
	}
}

void solve() {
	poss.clear();
	res.first = LINF;
	cin >> a[0] >> a[1];
	for (int i = 0; i < a[0].size(); i++) {
		for (int j = 0; j < 2; j++) {
			if (a[j][i] == '?') {
				poss.push_back(i + (j << 6));
			}
		}
	}
	brute();
	for (int i = (int) a[0].size() - 1; i >= 0; i--) {
		a[0][i] = '0' + res.second.first % 10;
		a[1][i] = '0' + res.second.second % 10;
		res.second.first /= 10;
		res.second.second /= 10;
	}
	cout << a[0] << " " << a[1];
}

int main() {
	ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
//    freopen("nextpartition.in", "r", stdin);
//    freopen("nextpartition.out", "w", stdout);
#endif
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "Case #" << i << ": ";
		solve();
		cout << "\n";
		cout.flush();
	}
	return 0;
}
