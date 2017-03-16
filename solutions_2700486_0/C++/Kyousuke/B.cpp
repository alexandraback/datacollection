#include <iostream>
#include <algorithm>
#include <limits>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <iomanip>
#include <cmath>
using namespace std;

#define forl(i, s, t) for(__typeof(s) i = s; i < t; i++)
#define rforl(i, s, t) for(__typeof(s) i = s; i > t; i--)
#define foreach(itr, c) forl(itr, (c).begin(), (c).end())
#define rforeach(itr, c) forl(itr, (c).rbegin(), (c).rend())

#define rep(n) forl(rep_c, 0, n)
#define fill2d_nn(g, s, z, v) forl(i, 0, s) fill_n(g[i], z, v)
#define fill2d_n(g, s, v) fill2d_nn(g, s, s, v)
//#define read(s, t) forloop(read_c, s, t) cin >> *read_c
//inline void read(ForwardIterator s, ForwardIterator e) { forloop(i, s, e) cin >> *i; }
//#define read_n(x, n) forl(read_n_c, 0, n) cin >> x[read_n_c]
//#define rread_n(x, n) rforl(rread_n_c, n-1, -1) cin >> x[rread_n_c]

#define tpop(x) (x).top(); (x).pop()
#define fpop(x) (x).front(); (x).pop()
//#define all(x) (x).begin(), (x).end()
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)

//#define chmin(a, b) a = min(a, b)
//#define chmax(a, b) a = max(a, b)
template<typename T> inline void chmin(T& a, const T& b) { a = min(a, b); }
template<typename T> inline void chmax(T& a, const T& b) { a = max(a, b); }

int gcd(int a, int b) { if(b == 0) return a; return gcd(b, a % b); }
#define gcd_n(a, n) accumulate(a+1, a+n, a[0], gcd);
template <class ForwardIterator>
inline int gcd_r(ForwardIterator s, ForwardIterator e) { return accumulate(s+1, e, s[0], gcd); }

#ifdef DEBUG
#define varcontent(v) #v << '=' << v
#define debug(v) cerr << varcontent(v) << endl
#define pdebug(v, w) cerr << '(' << varcontent(v) << ',' << varcontent(w) << ')' << endl
#define dmsg(a) cerr << a << endl
#else
#define varcontent(v) 0
#define debug(v) 0
#define pdebug(v, w) 0
#define dmsg(a) 0
#endif

#define printarr(a, n) cerr << #a << " = ["; forloop(i, 0, n) cerr << a[i] << ' '; cerr.seekp(cerr.tellp()-1L); cerr << ']' << endl
#define printgrid(g, y, x) cerr << endl << #g << ':' << endl; forl(i, 0, y) { forl(j, 0, x) cerr << g[i][j] << ' '; cerr << endl; } cerr << endl
#define rprintgrid(g, x, y) cerr << endl << #g << ':' << endl; forl(i, 0, x) { forl(j, 0, y) cerr << g[j][i] << ' '; cerr << endl; } cerr << endl
/*inline void printgrid(RandomAccessIterator g, int y, int x) {
	cerr << endl << #g << ':' << endl;
	forloop(i, 0, y) {
		forloop(j, 0, x) cout<< g[i][j] << ' ';
		cout << endl;
	}
	cerr << endl;
}*/
/*inline void rprintgrid(RandomAccessIterator g, int x, int y) {
	cerr << endl << #g << ':' << endl;
	forloop(i, 0, x) {
		forloop(j, 0, y) cout<< g[j][i] << ' ';
		cout << endl;
	}
	cerr << endl;
}*/

unsigned long lsqrt(unsigned long x, unsigned long lo = 0, unsigned long hi = numeric_limits<unsigned int>::max()) {
	unsigned long mid = (lo+hi)/2;
	if(lo == mid) return mid;
	if(x < mid*mid) return lsqrt(x, lo, mid);
	else if(x > mid*mid) return lsqrt(x, mid, hi);
	return mid;
}

const int INF = numeric_limits<int>::max()/2;
const double EPS = INF*numeric_limits<double>::epsilon();

double sim(long N, long Y, long X, long l, long r) {
	cerr << (2+l+r) << endl;
	if(X < 0 && l == Y) return 1.0 / (1l<<(2+l+r));
	if(X > 0 && r == Y) return 1.0 / (1l<<(2+l+r));
	double ans = 0.0;
	if(N > 0) {
		if(l+1 < abs(X)+Y) ans += sim(N-1, Y, X, l+1, r);
		if(r+1 < abs(X)+Y) ans += sim(N-1, Y, X, l, r+1);
	}
	return ans;
}

void gcjmain() {
	long N, X, Y;
	cin >> N >> X >> Y;
	int shell = (abs(X)+Y) / 2;
	shell += 1;
	vector<int> base;
	base.reserve(100);
	base.push_back(0);
	base.push_back(1);
	forl(i, 2, 100) {
		base.push_back(4 + 2*base[i-1] - base[i-2]);
	}
	cerr << shell << ' ' << base[shell] << endl;
	if(N >= base[shell]-abs(X)) cout << 1.0;
	else if(N <= base[shell-1]) cout << 0.0;
	else {
		cout << setprecision(8) << sim(N - base[shell-1], Y, X, -1, -1);
	}
	cout << endl;
}

int main() {
	int T;
	cin >> T;
	forl(t, 1, T+1) {
		cerr << "Case: " << t << '/' << T << endl;
		cout << "Case #" << t << ": ";
		gcjmain();
	}
}
