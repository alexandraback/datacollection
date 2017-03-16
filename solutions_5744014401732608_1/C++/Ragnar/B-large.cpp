#define HEADER_H
//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i,n)	for(auto i=decltype(n)(0); i<(n); ++i)
#define all(v)		begin(v), end(v)
using namespace std;		using ull= unsigned long long;
using ll = long long;		using ld = long double;
using vi = vector<ll>;		using vvi= vector<vi>;
using vb = vector<bool>;	using ii = pair<ll,ll>;
constexpr bool LOG = true;
void Log() { if(LOG) cerr << "\n"; }
template<class T, class... S> void Log(T t, S... s){
	if(LOG) cerr << t << "\t", Log(s...);
} /* ============== END OF HEADER ============== */
int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	ll TC; cin >> TC;
	for(ll tc = 1; tc<=TC; ++tc){
		cout << "Case #"<<tc<<": ";

		ll n,m; cin >> n >> m;

		if(m > (1<<(n-2))){
			cout << "IMPOSSIBLE\n";
			cout.flush();
			continue;
		}

		cout << "POSSIBLE\n";

		array<ll, 6> dp;
		dp.fill(0);
		for(ll i=0; i<n; ++i){
			for(ll j=0;j<n;++j){
				// from i to j
				if(j<=i) cout << '0';
				else {
					if(i>0) cout << '1', dp[j]+=dp[i];
					else {
						if(m==1<<(n-2))
							cout << '1', dp[j]+=dp[i];
						else {
							if(m&(1<<(n-2-j)))
								cout << '1', dp[j]+=dp[i];
							else
								cout << '0';
						}
						
					}
				}

			}
			cout << '\n';
		}
		cout.flush();

	}
	return 0;
}


