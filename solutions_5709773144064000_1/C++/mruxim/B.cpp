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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int testn; cin >> testn;
	for(int testc = 1; testc <= testn; testc++) {
		double C, F, X;
		cin >> C >> F >> X;

		double ans = 1e9;

		double cur_time = 0, cur_rate = 2;
		rep(i, 100000+100) {
			smin(ans, cur_time + X / cur_rate);
			cur_time += C / cur_rate;
			cur_rate += F;
		}

		cout << "Case #" << testc << ": ";
		cout.setf(ios::fixed);
		cout.precision(8);
		cout << ans << endl;
	}

	{ return 0; }
}

