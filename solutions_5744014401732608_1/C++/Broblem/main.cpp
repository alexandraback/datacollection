#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define deg(a) cout << #a << " = " << a << '\n'

using namespace std;

const int N = 100;

int n;
ll m;
char g[N][N];

void solve(int test) {
	cout << "Case #" << test << ": ";
	cin >> n >> m;
	if (m > (1ll << (n - 2))) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	cout << "POSSIBLE\n";
	memset(g, '0', sizeof(g));
	for (int i = 1; i < n; ++i) {
		g[0][i] = '1';
	}
	--m;
	for (int i = 1; i <= n - 2; ++i) {
		for (int j = i + 1; j <= n - 2; ++j) {
			g[i][j] = '1';
		}
	}
	for (int i = 0; i < n - 2; ++i) {
		if ((m & (1ll << i)) != 0) {
			g[i + 1][n - 1] = '1';
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << g[i][j];
		}
		cout << '\n';
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
