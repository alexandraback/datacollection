#define HEADER_H
#define _GLIBCXX_DEBUG
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


using P = array<ll,10>;
using Q = array<P,10>;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	ll TC; cin >> TC;
	for(ll tc = 1; tc<=TC; ++tc){
		cout << "Case #"<<tc<<": ";

		ll a,b,c,k; cin >> a >> b >> c >> k;
		if(k>c) k=c;

		cout << a*b*k << '\n';

		Q ab, bc, ca;
		for(auto &x:ab)x.fill(0);
		for(auto &x:bc)x.fill(0);
		for(auto &x:ca)x.fill(0);

		for(ll l=1;l<=c;++l){
			ll i=(k*(l-1))%a+1;
			for(ll j=1;j<=b; ++j){
				for(ll x=1;x<=min(a, a*k/c); ++x){
					cout << i << ' ' << j << ' ' << l << '\n';
					++ab[i-1][j-1];
					++bc[j-1][l-1];
					++ca[l-1][i-1];
					++i;
					if(i==a+1) i=1;
				}
			}
		}
		cout.flush();

		for(ll i=0; i<10; ++i)
			for(ll j=0;j<10; ++j)
				if(ab[i][j]>k){
					Log("ab",i,j,ab[i][j]);
					assert(false);
				}
		for(ll i=0; i<10; ++i)
			for(ll j=0;j<10; ++j)
				if(bc[i][j]>k){
					Log("bc",i,j,bc[i][j]);
					assert(false);
				}
		for(ll i=0; i<10; ++i)
			for(ll j=0;j<10; ++j)
				if(ca[i][j]>k){
					Log("ca",i,j,ca[i][j]);
					assert(false);
				}


	}
	return 0;
}


