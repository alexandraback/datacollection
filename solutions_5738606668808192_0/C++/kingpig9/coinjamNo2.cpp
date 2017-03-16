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

int N, J;

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	scanf("%*d %d %d", &N, &J);
	puts("Case #1:");
	for (int i = 3; i <= 2 * J + 1; i += 2) {
		vector<int> bits;
		for (int j = i; j; j >>= 1) {
			bits.pb(j & 1);
		}
		reverse(all(bits));

		for (int j : bits) {
			printf("%d", j);
		}

		for (int j = 0; j < N - 2 * int(bits.size()); j++) {
			printf("0");
		}

		for (int j : bits) {
			printf("%d", j);
		}

		reverse(all(bits));

		for (int b = 2; b <= 10; b++) {
			int p = 1;
			int ans = 0;
			for (int j : bits) {
				ans += j * p;
				p *= b;
			}
			printf(" %d", ans);
		}
		puts("");
	}
}