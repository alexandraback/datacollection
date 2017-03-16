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

int L, X;
string s, t;



string run() {
	cin >> L >> X;
	cin >> t;

	s = "";
	rep(i, min(X, X % 4 + 8)) s += t;

	int phase = 0;

	int sgn = 1;
	char cur = '1';
	for(char ch: s) {
		if(cur == '1')
			cur = ch;
		else if(cur == ch)
			sgn *= -1, cur = '1';
		else
			sgn *= (((cur-'i')+1)%3 == (ch-'i') ? 1 : -1), cur = 'i' + 'j' + 'k' - cur - ch;
		if(phase == 0 && sgn == 1 && cur == 'i') phase = 1;
		if(phase == 1 && sgn == 1 && cur == 'k') phase = 2;
	}
	
	return (phase == 2 && sgn == -1 && cur == '1') ? "YES" : "NO";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tt; cin >> tt;
	fer(tc, 1, tt+1) {
		cout << "Case #" << tc << ": " << run() << endl;
	}

	return 0;
}

