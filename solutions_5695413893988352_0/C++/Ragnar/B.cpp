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

bool match(string s, ll x){
	ll l = s.size();
	ll y=x;
	for(ll i=0; i < s.size(); ++i){
		ll d = x%10;
		x/=10;
		char c = s[s.size()-1-i];
		if(c != '?' && d+'0' != c)
			return false;
	}

	return true;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	ll TC; cin >> TC;
	for(ll tc = 1; tc<=TC; ++tc){
		cout << "Case #"<<tc<<": ";
		string a,b; cin >> a >> b;
		array<bool, 1000> apos, bpos;
		ll length = a.size();
		ll pow = length==1 ? 10 : (length == 2?100:1000);
		for(ll i = 0; i<pow; ++i){
			apos[i]=match(a,i);
			bpos[i]=match(b,i);
		}

		pair<ll,ii> best = {1000000,{-1,-1}};
		for(ll i =0; i<pow; ++i)
			for(ll j=0; j < pow; ++j)
				if(apos[i] && bpos[j] && abs(i-j) < best.first)
					best = {abs(i-j),{i,j}};
		cout <<setfill('0')<< setw(length) << best.second.first << ' ' << setw(length) <<setfill('0')<< best.second.second << '\n';
	}
	return 0;
}


