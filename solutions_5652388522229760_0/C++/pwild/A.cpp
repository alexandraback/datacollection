#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

int main() {
	ll TC; cin >> TC;
	FOR(tc,1,TC+1) {
		ll n; cin >> n;
		cout << "Case #" << tc << ": ";
		if (!n) {
			cout << "INSOMNIA" << endl;
			continue;
		}
		ll m = 0, mask = 0;
		while (mask < 1023) {
			m += n;
			ll mm = m;
			while (mm) mask |= 1 << (mm%10), mm /= 10;
		}
		cout << m << endl;
	}
}

