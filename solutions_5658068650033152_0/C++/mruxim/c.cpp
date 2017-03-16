// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

bool g[25][25];

int dfs(int x, int y) {
	if(x < 0 || y < 0 || x >= 25 || y >= 25 || g[x][y] == 1) return 0;
	g[x][y] = 1;
	return 1 + dfs(x+1, y) + dfs(x-1, y) + dfs(x, y+1) + dfs(x, y-1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tt; cin >> tt;
	for(int tc = 1; tc <= tt; tc++) {
		int n, m, k;
		cin >> n >> m >> k;
		int ans = min(n+n+m+m, k);
		
		rep(mask, 1<<(n*m)) {
			int t = __builtin_popcount(mask);
			if(t >= ans) continue;
			memset(g, false, sizeof g);
			rep(i, n) rep(j, m) g[i+2][j+2] = mask >> (i * m + j) & 1;
			int rem = 25*25 - dfs(0, 0);
			if(rem >= k) smin(ans, t);
		}

		cout << "Case #" << tc << ": " << ans << endl;
	}

	{ return 0; }
}

