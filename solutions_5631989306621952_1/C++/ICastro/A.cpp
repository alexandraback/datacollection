#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define INF numeric_limits<int>::max()
#define LINF numeric_limits<ll>::max()
#define mp make_pair
#define mt make_tuple
#define getT(T, p) get<p>(T)
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
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vii;

const double EPS = 1e-8;
//const double PI = atan(1.0)*4;
const double PI = 2*acos(0.0);
inline int cmp(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int main(void) {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		string s;
		cin >> s;
		string sai;
		sai.pb(s[0]);
		for (int i = 1; i < sz(s); ++i) {
			if (s[i] >= sai[0]){
				sai.insert(0, string(1, s[i]));
			} else {
				sai.pb(s[i]);
			}
		}
		cout << "Case #" << t+1 << ": " << sai << endl;
	}

	return 0;
}
