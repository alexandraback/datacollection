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

int n;
string s;

int run() {
	cin >> n >> s;
	int cnt = 0;
	int tot = s[0] - '0';
	fer(i, 1, n+1) {
		if(tot < i)
			cnt += i - tot,
			tot = i;
		tot += s[i] - '0';
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tt;
	cin >> tt;
	fer(tc, 1, tt+1)
		cout << "Case #" << tc << ": " << run() << endl;

	return 0;
}

