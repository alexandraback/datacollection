#include <bits/stdc++.h>

using namespace std;

#define fillchar(a, s) memset((a), (s), sizeof(a))
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define rep(it, v) for (auto it = (v).begin(); it != (v).end(); it++)
#define rfile(f) freopen(f, "r", stdin)
#define wfile(f) freopen(f, "w", stdout)
#define rwfile(prob) rfile(prob".in"); wfile(prob".out")
#define pb push_back
#define mpair make_pair
#define fi first
#define se second
#define dri(x) scanf("%d", &x)
#define drii(x, y) scanf("%d %d", &x, &y)
#define driii(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define driiii(x, y, z, w) scanf("%d %d %d %d", &x, &y, &z, &w)
#define drl(x) scanf("%lld", &x)
#define drll(x, y) scanf("%lld %lld", &x, &y)
#define drlll(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define drllll(x, y, z, w) scanf("%lld %lld %lld %lld", &x, &y, &z, &w)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 16;

int cid;
unordered_map<string, int> id;
int N, A[MAXN][2];

int getid (string s) {
	return id.count(s) ? id[s] : (id[s] = cid++);
}

bool vis[2 * MAXN][2];

int solve() {
#warning reset
	cid = 0;
	id.clear();
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			string s;
			cin >> s;
			A[i][j] = getid(s);
		}
	}

	int ans = 0;

	for (int i = 0; i < (1 << N); i++) {
		//get the #s that could be true
		fillchar(vis, 0);
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				for (int k = 0; k < 2; k++) {
					vis[A[j][k]][k] = true;
				}
			}
		}

		bool ok = true;
		for (int j = 0; j < N; j++) {
			if (!(i & (1 << j))) {
				if (!(vis[A[j][0]][0] && vis[A[j][1]][1])) {
					ok = false;
					break;
				}
			}
		}

		if (ok) {
			ans = max(ans, N - __builtin_popcount(i));
		}
	}
	return ans;
}

int main() {
	if (fopen("input.txt", "r")) {
		rfile("input.txt");
		wfile("output.txt");
	}
	ios::sync_with_stdio(false);

	int ncas;
	cin >> ncas;
	for (int cas = 1; cas <= ncas; cas++) {
		cout << "Case #" << cas << ": " << solve() << '\n';
	}
}