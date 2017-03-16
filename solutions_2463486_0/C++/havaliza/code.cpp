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

bool pal(ll x) {
	ll tmp = x, y = 0;
	while (tmp) y = y*10+tmp%10, tmp /= 10;
	return x == y;
}

int main() {
	vector<ll> v;
	for (ll i = 1; i*i <= 1e14; i++)
		if (pal(i) && pal(i*i))
			v.pb(i*i);
	int tc;
	cin >> tc;
	for (int l = 1; l <= tc; l++) {
		cout << "Case #" << l << ": ";
		ll A, B;
		cin >> A >> B;
		cout << upper_bound(all(v), B)-lower_bound(all(v), A) << endl;
	}
	return 0;
}

