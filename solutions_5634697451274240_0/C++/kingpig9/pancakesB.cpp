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
const int MAXN = 110;

char buf[MAXN];
int N, A[MAXN];
int ans;

void print() {
	puts("DATA:");
	for (int i = 0; i < N; i++) {
		printf("%c", A[i] ? '+' : '-');
	}
	puts("");
}

void flip (int x) {
	if (x == 0) {
		return;
	}
	ans++;
	reverse(A, A + x);
	for (int i = 0; i < x; i++) {
		A[i] ^= 1;
	}
	// print();
}

void solve() {
#warning reset.
	ans = 0;
	scanf("%s", buf);
	N = strlen(buf);
	for (int i = 0; i < N; i++) {
		A[i] = (buf[i] == '+');
	}

	for (int i = N - 1; i >= 0; i--) {
		if (A[i]) {
			continue;
		}
		//while the top is +, flip it!
		int ntop = 0;
		for (; ntop <= i; ntop++) {
			if (A[ntop] == 0) {
				break;
			}
		}

		// printf("i = %d, ntop = %d\n", i, ntop);

		if (ntop == i + 1) {
			flip(i + 1);
		} else {
			// printf("double flip, %d and %d\n", ntop, i + 1);
			flip(ntop);
			flip(i + 1);
		}
	}
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	
	int nt;
	dri(nt);
	for (int cas = 1; cas <= nt; cas++) {
		printf("Case #%d: ", cas);
		solve();
		printf("%d\n", ans);
	}
}