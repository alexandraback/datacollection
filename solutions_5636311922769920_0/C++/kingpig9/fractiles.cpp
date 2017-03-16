#include <bits/stdc++.h>

using namespace std;

#define fillchar(a, s) memset((a), (s), sizeof(a))
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define rep(it, v) for (auto it = (v).begin(); it != (v).end(); it++)
#define rwfile(f) freopen(f".in", "r", stdin); freopen(f".out", "w", stdout)
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

int K, C, S;

void solve() {
	driii(K, C, S);
	//S >= ceil(K / C) -> S * C >= K

	if (S < (K + C - 1) / C) {
		puts(" IMPOSSIBLE");
		return;
	}

	for (int i = 0; i < K; i += C) {
		//[i, min(K, i + C)), but remember to advance the thing even if >= K
		ll res = 0;
		for (int j = i; j < i + C; j++) {
			if (j < K) {
				res = K * res + j;
			} else {
				res *= K;
			}
		}
		printf(" %lld", res + 1);
	}
	puts("");
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}

	int ncas;
	dri(ncas);
	for (int cas = 1; cas <= ncas; cas++) {
		printf("Case #%d:", cas);
		solve();
	}
}