#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define deg(a) cout << #a << " = " << a << '\n'

using namespace std;

const int N = 100;

int n, m, s, k;
int cnt[3][15][15];
vector<int> a, b, c;

void solve(int test) {
	memset(cnt, 0, sizeof(cnt));
	cin >> n >> m >> s >> k;
	a.clear();
	b.clear();
	c.clear();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int l = 1; l <= s; ++l) {
				if (cnt[0][i][j] < k && cnt[1][i][l] < k && cnt[2][j][l] < k) {
					a.push_back(i);
					b.push_back(j);
					c.push_back(l);
					cnt[0][i][j]++;
					cnt[1][i][l]++;
					cnt[2][j][l]++;
				}
			}
		}
	}
	cout << "Case #" << test << ": " << a.size() << "\n";
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] << ' ' << b[i] << ' ' << c[i] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
#ifdef KOBRA
	freopen("toster", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#endif // KOBRA
	int cases;
	cin >> cases;
	for (int i = 1; i <= cases; ++i) {
		solve(i);
	}
	return 0;
}
