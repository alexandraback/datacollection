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

string s[55];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int testn; cin >> testn;
	for(int testc = 1; testc <= testn; testc++) {
		int R, C, M;
		cin >> R >> C >> M;
		int E = R * C - M;

		cout << "Case #" << testc << ":" << endl;

		rep(r, R) s[r] = string(C, '*');
		if(min(R, C) == 1 || E == 1 || (min(R, C) == 2 && E % 2 == 0 && E != 2)) {
			if(C == 2) { rep(r, R) rep(c, C) if(E) s[r][c] = '.', E--; }
			else { rep(c, C) rep(r, R) if(E) s[r][c] = '.', E--; }
		}
		else if(min(R, C) == 2 || E <= 3 || E == 5 || E == 7)
			{ cout << "Impossible" << endl; continue; }
		int OE = E;
		rep(c, C) {
			if(E) s[0][c] = '.', E--;
			if(E) s[1][c] = '.', E--;
		}
		if(OE < 2*C) {
			if(OE % 2)
				s[0][(OE-1)/2] = s[0][(OE-1)/2-1] = s[1][(OE-1)/2-1] = '*',
				s[2][0] = s[2][1] = s[2][2] = '.';
		}
		else if(E) {
			OE = E;
			fer(r, 2, R) rep(c, C) if(E) s[r][c] = '.', E--;
			if(OE % C == 1) {
				s[2 + OE / C][1] = '.', s[1 + OE / C][C-1] = '*';
				if(1 + OE / C == 1)
					s[2 + OE / C][2] = '.', s[OE / C][C-1] = '*';
				
			}
		}
		s[0][0] = 'c';
		rep(r, R) cout << s[r] << endl;
	}

	{ return 0; }
}

