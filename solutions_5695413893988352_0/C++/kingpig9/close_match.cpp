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
const int MAXN = 20;

int N;
char S[MAXN], T[MAXN];

void print (int x, int n) {
	string s = to_string(x);
	for (int i = 0; i + s.size() < n; i++) {
		printf("0");
	}
	printf(s.c_str());
}

void solve() {
	scanf("%s %s", S, T);
	N = strlen(S);

	reverse(S, S + N);
	reverse(T, T + N);
	for (int i = N; i < 3; i++) {
		S[i] = '0';
		T[i] = '0';
	}

	pair<int, pii> ans;
	ans.fi = INT_MAX;

	for (int i = 0; i < 1000; i++) {
		string si = to_string(i);
		reverse(all(si));
		while (si.size() < 3) {
			si += '0';
		}

		bool goodi = true;

		for (int j = 0; j < 3; j++) {
			if (S[j] != '?' && S[j] != si[j]) {
				goodi = false;
				break;
			}
		}

		if (!goodi) {
			continue;
		}

		for (int j = 0; j < 1000; j++) {
			string sj = to_string(j);
			reverse(all(sj));
			while (sj.size() < 3) {
				sj += '0';
			}

			bool goodj = true;

			for (int k = 0; k < 3; k++) {
				if (T[k] != '?' && T[k] != sj[k]) {
					goodj = false;
					break;
				}
			}

			if (goodj) {
				ans = min(ans, mpair(abs(i - j), pii(j, i)));
			}
		}
	}
	print(ans.se.se, N);
	printf(" ");
	print(ans.se.fi, N);
	puts("");
}

int main() {
	if (fopen("input.txt", "r")) {
		rfile("input.txt");
		wfile("output.txt");
	}
	int ncas;
	dri(ncas);
	for (int cas = 1; cas <= ncas; cas++) {
		printf("Case #%d: ", cas);
		solve();
	}
}