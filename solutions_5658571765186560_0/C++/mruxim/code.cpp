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

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const string ans[2] = {"RICHARD", "GABRIEL"};

int run() {
	int p, x, y;
	cin >> p >> x >> y;
	if(x > y) swap(x, y);

	if(x*y % p) return 0;
	if(y < p) return 0;
	if(x < (p+1)/2) return 0;
	if(p > 6) return 0;

	if(p == 1) return 1;
	if(p == 2) return 1;
	if(p == 3) return 1;
	if(p == 4) return x >= 3;
	if(p == 5) return x >= 4 || y != 5;
	if(p == 6) return x >= 4;

	return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tt;
	cin >> tt;
	fer(tc, 1, tt+1)
		cout << "Case #" << tc << ": " << ans[run()] << endl;

	return 0;
}

