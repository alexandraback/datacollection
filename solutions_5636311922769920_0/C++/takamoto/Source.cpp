#include <bits/stdc++.h>
using namespace std;
 
using ll = long long; using ld = long double;
using vi  = vector<int>; using vb  = vector<bool>; using vd  = vector<double>; using vl  = vector<ll>;
using vvi = vector<vi>;  using vvb = vector<vb>;   using vvd = vector<vd>;     using vvl = vector<vl>;
 
#define REP(i,n) for(ll i=0; i<(n); ++i)
#define FOR(i,b,n) for(ll i=(b); i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()
#define TEN(x) ((ll)1e##x)
 
template<typename V, typename T> inline void fill(V& x, const T& val){ x = val; }
template<typename V, typename T> inline void fill(vector<V>& vec, const T& val){ for(auto& v: vec) fill(v, val); }
template<typename T> inline vector<T> operator+(vector<T> lhs, const vector<T> & rhs) { lhs.insert(lhs.end(), ALL(rhs)); return lhs; }
template<typename T> inline istream& operator>>(istream& is, vector<T>& vec){ for(T& x: vec) is >> x; return is; }
template<typename T> inline string join(const vector<T>& vec, string sep = " ") { stringstream ss; REP(i, vec.size()) ss << vec[i] << ( i+1 == vec.size() ? "" : sep ); return ss.str(); }
 
const ll MOD = 1777777777;
const double EPS = 1e-10;

string to_bit_s(ll i, ll n) {
	string s;
	while (i > 0) {
		s.push_back('0' + (i & 1));
		s.push_back('0' + (i & 1));
		i >>= 1;
	}
	reverse(ALL(s));
	ll x = s.size();
	REP(i, n - 4 - x) {
		s = "0" + s;
	}
	s = "11" + s + "11";
    return s;
}

int main() {
#ifdef INPUT_FROM_FILE
	std::ifstream cin("sample.in");
	std::ofstream cout("sample.out");
#endif
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(30);
	ll t; cin >> t;
	ll mod = TEN(9) + 7;
	REP (c, t) {
		cout << "Case #" << c+1 << ":";
		
		ll K, C, S; cin >> K >> C >> S;
		ll KpowC = pow(K, C);

		ll ans = max<ll>(1, (K%C!=0 ? K/C+1: K/C));
		if(ans>S){
			cout << " IMPOSSIBLE" << endl;
		}else{
			REP(i, ans){
				if (K < C) C = K;
				
				ll v = 0;
				ll Kpow_d = 1;
				REP(d, C){
					v += min(K-1, (i*C) + (C - 1) - d) * Kpow_d;
					Kpow_d *= K;
				}
				cout << " " << v+1;
			}
			cout << endl;
		}
	}
	return 0;
}