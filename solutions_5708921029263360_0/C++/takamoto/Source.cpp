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
		ll j, p, s, k;
		cin >> j >> p >> s >> k;
		vector<vvl> table_2(3, vvl(s, vl(s, 0)));
		vector<ll> cur = { 0, 0, 0 };
		ll cnt = 0;
		vector<vl> ans;
		while (true) {
			bool valid = true;
			REP(i, 3) if (table_2[i][cur[0 + i]][cur[(1 + i) % 3]] >= k) valid = false;
			if (valid) {
				REP(i, 3) table_2[i][cur[0 + i]][cur[(1 + i) % 3]]++;
				cnt++;
				ans.push_back(cur);
			}
			if (cur[0] % 2==0 && cur[2] < s - 1) cur[2]++;
			else if (cur[0] % 2 != 0 && cur[2] > 0) cur[2]--;
			else if (cur[1] < p - 1) {
				cur[1]++;
				cur[2] = (cur[0] % 2==0 ? 0 : s-1);
			} else if (cur[0] < j - 1) {
				cur[0]++;
				cur[1] = 0;
				cur[2] = (cur[0] % 2==0 ? 0 : s-1);
			} else {
				break;
			}
		}
		cout << "Case #" << _ + 1 << ": " << ans.size() << endl;
		REP(i, ans.size()) {
			REP(j, 3) ans[i][j]++;
			cout << join(ans[i]) << endl;
		}
	}

	return 0;
}