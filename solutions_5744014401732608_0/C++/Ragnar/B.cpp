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
		array<array<ll,6>,6> index;
		// index[a][b]: bit index of edge from a to b
		ll in = 0;
		for(ll a=0; a<n; ++a)
			for(ll b=a+1;b<n;++b)
				index[a][b] = in++;

		for(ll mask=0;mask< (1<<in); ++mask){
			array<ll,6> dp;
			dp.fill(0);
			dp[0]=1;
			for(ll b=1; b<n; ++b){
				for(ll a=0;a<b; ++a)
					if(mask&(1<<index[a][b]))
						dp[b] += dp[a];
			}
			if(dp[n-1]==m){
				cout << "POSSIBLE\n";
				for(ll i=0;i<n; ++i){
					for(ll j=0;j<n; ++j)
						cout << (j>i && mask&(1<<index[i][j]) ? '1' : '0');
					cout << '\n';
				}
				goto end;
			}
		}
		cout << "IMPOSSIBLE" << '\n';

end:;

	}
	return 0;
}


