#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ulint unsigned long long int
#define lint long long int
#define ll long long
#define INF numeric_limits<int>::max()
#define LINF numeric_limits<ll>::max()
#define mp make_pair
#define mt make_tuple
#define getH(T) get<0>(T)
#define getD(T) get<1>(T)
#define getC(T) get<2>(T)
#define pb push_back
#define st first
#define nd second
#define contOnes __builtin_popcountl
#define powDI __builtin_powi
#define sz(v) int(v.size())
//cuidado parametro duplicados
#define all(X) (X).begin(), (X).end()
#define logLow(X) (X <= 0 ? 0 : 31 - __builtin_clz(X))
#define logUpper(X) (X <= 1 ? 0 : 32 - __builtin_clz(X-1))
#define pow2(X) ((X)*(X))

//const double PI = atan(1.0)*4;
const double PI = 2*acos(0.0);

int main(void) {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int k, c, s;
		cin >> k >> c >> s;
		if (s < (k+c-1)/c){
			cout << "Case #" << t + 1 << ": IMPOSSIBLE" << endl;
		} else {
			vector<ll> sai;
			ll l = 0;
			ll m = 1;
			for (int i = 0; i < c; ++i) m *= k;
			for (int i = 0; i < k; ++i){
				m /= k;
				l += m*i;
				if ((i + 1)%c == 0 || i + 1 == k){
					sai.pb(l+1);
					l = 0;
					m = powDI(k, c);
				}
			}
			cout << "Case #" << t + 1 << ":";
			for (int i = 0; i < sz(sai); ++i){
				cout << " " << sai[i];
			}
			cout << endl;
		}
	}
	return 0;
}
