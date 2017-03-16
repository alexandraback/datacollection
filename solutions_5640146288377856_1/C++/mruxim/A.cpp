// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

int solve() {
	int n, m, w;
	cin >> n >> m >> w;
	if(w == 1) return n * m;

	vector<int> v;
	rep(i, n) rep(j, m) if((i + j) % w == w-1) {
		int a = (w < n && i > 0 && i < n-1);
		int b = (w < m && j > 0 && j < m-1);
		v.pb(a + b);
	}
	sort(all(v), greater<int>());
	int ans = 0;
	rep(i, sz(v))
		smax(ans, i + v[i] + w);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tt; cin >> tt;
	fer(tc, 1, tt+1) {
		cout << "Case #" << tc << ": " << solve() << endl;
	}

	return 0;
}

