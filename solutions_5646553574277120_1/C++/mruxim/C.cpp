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
	int c, n, v;
	cin >> c >> n >> v;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	sort(all(a));

	int ans = 0;
	ll sum = 0;

	while(sum < v) {
		int pos = upper_bound(all(a), sum+1) - a.begin();
		ll tmp = 0;
		rep(i, pos) tmp += c * a[i];
		if(tmp > sum) sum = tmp;
		else {
			ans++;
			a.pb(sum + 1);
			sort(all(a));
		}
	}

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

