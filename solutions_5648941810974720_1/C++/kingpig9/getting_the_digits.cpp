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

char S[2010];
int cnt[256];
int ans[256];
string nums[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
string uniq = "ZOWHUFXSGN";

void remove (int num) {
	while (cnt[uniq[num]]) {
		for (char c : nums[num]) {
			cnt[c]--;
		}
		ans[num]++;
	}
}

void solve() {
	scanf("%s", S);
	fillchar(cnt, 0);
	fillchar(ans, 0);
	for (int i = 0; S[i]; i++) {
		cnt[S[i]]++;
	}

	for (int x : {0, 2, 4, 6, 8, 1, 3, 7, 5, 9}) {
		remove(x);
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < ans[i]; j++) {
			printf("%d", i);
		}
	}
	puts("");
}

int main() {
	if (fopen("input.txt", "r")) {
		rfile("input.txt");
		wfile("output.txt");
	}
	int tt;
	dri(tt);

	for (int cas = 1; cas <= tt; cas++) {
		printf("Case #%d: ", cas);
		solve();
	}
}