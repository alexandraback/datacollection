#include <bits/stdc++.h>
using namespace std;

using ll = long long; using ld = long double; using ull = unsigned long long; using uint = unsigned int;
using vi  = vector<int>; using vb  = vector<bool>; using vd  = vector<double>; using vl  = vector<ll>;
using vvi = vector<vi>;  using vvb = vector<vb>;   using vvd = vector<vd>;     using vvl = vector<vl>;

#define REP(i,n) for(ll i=0; i<(n); ++i)
#define FOR(i,b,n) for(ll i=(b); i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()
#define TEN(x) ((ll)1e##x)

template<typename T> inline string join(const vector<T>& vec, string sep = " ") { stringstream ss; REP(i, vec.size()) ss << vec[i] << ( i+1 == vec.size() ? "" : sep ); return ss.str(); }

int main() {
#ifdef INPUT_FROM_FILE
	ifstream cin("sample.in");
	ofstream cout("sample.out");
#endif
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(30);

	ll t; cin >> t;
	REP(_, t) {
		ll b, m; cin >> b >> m;
		cout << "Case #" << _ + 1 << ": ";
		if (m > 1 << (b - 2)) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		cout << "POSSIBLE" << endl;

		vl pat(b);
		pat[0] = pat[1] = 1;

		ll size = 1;
		FOR(i, 2, b) {
			if (pat[i - 1] * 2 >= m) {
				size = i;
				break;
			}
			pat[i] = pat[i-1] * 2;
		}

		vb used(size, false);
		for (ll i = size - 1; i >= 0; --i) {
			if (m >= pat[i]) {
				used[i] = true;
				m -= pat[i];
			}
		}

		REP(i, size) {
			REP(j, size) {
				cout << (i < j ? 1 : 0);
			}
			FOR(j, size, b-1) cout << 0;
			cout << (used[i] ? 1 : 0);
			cout << endl;
		}
		FOR(i, size, b) {
			REP(j, b) cout << 0;
			cout << endl;
		}
	}

	return 0;
}