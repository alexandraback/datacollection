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


using P = array<ll,3>;
using Q = array<P,3>;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	map<array<ll,4>,ll> m;

	ll TC; cin >> TC;
	for(ll tc = 1; tc<=TC; ++tc){
		cout << "Case #"<<tc<<": ";

		ll a,b,c,k; cin >> a >> b >> c >> k;
		if(k>c) k=c;
		vector<P> ps;
		for(ll i=0;i<a;++i)
			for(ll j=0;j<b;++j)
				for(ll l=0;l<c; ++l)
					ps.push_back({{i,j,l}});
		array<ll,4> x{{a,b,c,k}};
		if(m.find(x)!=m.end()){
			ll mask= m.find(x)->second;
			cout << __builtin_popcount(mask) << '\n';


			for(ll i=0;i<ps.size(); ++i)
				if(mask & (1<<i)){
					cout << 1+ps[i][0]<<' '<<1+ps[i][1]<<' '<<1+ps[i][2]<<'\n';
				}

			continue;
		}

		ii best{0,0};
		for(ll mask=0; mask<(1<<ps.size()); ++mask){
			ll cnt = 0;
			Q ab, bc, ca;
			for(auto &x:ab)x.fill(0);
			for(auto &x:bc)x.fill(0);
			for(auto &x:ca)x.fill(0);
			for(ll i=0;i<ps.size(); ++i)
				if(mask&(1<<i)){
					++cnt;
					++ab[ps[i][0]][ps[i][1]];
					if(ab[ps[i][0]][ps[i][1]]>k)
						goto end;
					++bc[ps[i][1]][ps[i][2]];
					if(bc[ps[i][1]][ps[i][2]]>k)
						goto end;
					++ca[ps[i][2]][ps[i][0]];
					if(ca[ps[i][2]][ps[i][0]]>k)
						goto end;
				}
			best = max(best, {cnt, mask});
end:;
		}

		cout << best.first << '\n';

		for(ll i=0;i<ps.size(); ++i)
			if(best.second & (1<<i)){
				cout << 1+ps[i][0]<<' '<<1+ps[i][1]<<' '<<1+ps[i][2]<<'\n';
			}

		cout.flush();

		m[x] = best.second;

	}
	return 0;
}


