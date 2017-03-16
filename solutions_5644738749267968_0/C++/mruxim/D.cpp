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

const int maxn = 1000 + 100;

int n;

int solve(double a[maxn], double b[maxn]) {
	rof(i, n+1, 0) {
		bool ok = true;
		rep(j, i) if(a[n-i+j] < b[j]) ok = false;
		if(ok) return i;
	}
	return -1;
}

double a[maxn];
double b[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int testn; cin >> testn;
	for(int testc = 1; testc <= testn; testc++) {
		cin >> n;
		rep(i, n) cin >> a[i];
		rep(i, n) cin >> b[i];
		sort(a, a+n);
		sort(b, b+n);

		cout << "Case #" << testc << ": " << solve(a, b) << ' ' << n - solve(b, a) << endl;
	}

	{ return 0; }
}

