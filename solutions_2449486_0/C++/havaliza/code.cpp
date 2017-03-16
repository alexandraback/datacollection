#include <algorithm> 
#include <iostream> 
#include <valarray> 
#include <iomanip> 
#include <fstream> 
#include <sstream> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <numeric> 
#include <complex> 
#include <cstdio> 
#include <string> 
#include <vector> 
#include <bitset> 
#include <ctime> 
#include <cmath> 
#include <queue> 
#include <stack> 
#include <deque> 
#include <map> 
#include <set> 

using namespace std; 

#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i) 
#define FOR(i, a, n) for (int i = (a); i < int(n); ++i) 
#define error(x) cout << #x << " = " << (x) << endl; 
#define all(n) (n).begin(), (n).end() 
#define Size(n) ((int)(n).size()) 
#define mk make_pair 
#define pb push_back 
#define F first 
#define S second 
//#define X real() 
//#define Y imag() 

int _;
#define scanf _ = scanf

typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef complex<double> point; 

template <class P, class Q> void smin(P &a, Q b) { if (b < a) a = b; } 
template <class P, class Q> void smax(P &a, Q b) { if (b > a) a = b; } 
template <class P, class Q> bool in(const P &a, const Q &b) { return a.find(b) != a.end(); } 

int main() {
	int tc;
	cin >> tc;
	for (int l = 1; l <= tc; l++) {
		cout << "Case #" << l << ": ";
		int n, m;
		cin >> n >> m;
		vector<vector<int> > v(n, vector<int>(m, 0));
		FOR(i, 0, n) FOR(j, 0, m) cin >> v[i][j];
		bool ok = true;
		FOR(i, 0, n) FOR(j, 0, m) {
			int mxr = -1, mxc = -1;
			FOR(k, 0, n) smax(mxc, v[k][j]);
			FOR(k, 0, m) smax(mxr, v[i][k]);
			ok &= v[i][j] >= mxr || v[i][j] >= mxc;
		}
		cout << (ok?"YES":"NO") << endl;
	}
	return 0;
}

