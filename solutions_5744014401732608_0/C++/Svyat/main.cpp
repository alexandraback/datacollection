#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

int T;
int n;
ll m;
char ans[51][51];

void load() {
	cin >> n >> m;
}

void solve(int tc) {
	printf("Case #%d: ", tc);
	if ((1ll << (n - 2)) < m) {
		puts("IMPOSSIBLE");
		return;
	}
	puts("POSSIBLE");
	for (int i = 0; i + 1 < n; ++i) {
		ans[i][i + 1] = '1';
	}
	int v = -1;
	ll sum = m;
	for (int i = n - 2; ; --i) {
		if ((1ll << (n - i - 2)) > m) {
			v = i + 1;
			sum -= 1ll << (n - i - 3);
			break;
		}
	}
	clog << v << endl;
	for (int i = v; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			ans[i][j] = '1';
		}
	}
	--v;
	for (int i = v + 1; i < n; ++i) {
		if (sum & (1ll << (n - i - 2))) {
			sum ^= 1ll << i;
			ans[v][i] = '1';
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			putchar(ans[i][j]);
		}
		puts("");
	}
}

void clear() {
	memset(ans, '0', sizeof ans);
}

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	clear();
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		clog << "Testcase " << tc << endl;
		load();
		solve(tc);
		clear();
	}
	return 0;
}