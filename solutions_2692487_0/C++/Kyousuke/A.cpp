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

void gcjmain() {
	int A, N;
	cin >> A >> N;
	vector<int> X(N);
	forl(n, 0, N) cin >> X[n];
	sort(X.begin(), X.end());
	//forl(n, 0, N) cerr << X[n] << ' ';
	//cerr << endl;
	int ins = 0;
	int cost = 0;
	forl(n, 0, N) {
		if(X[n] < A) A += X[n];
		else {
			//delete everything
			if(cost == 0) cost = N-n+ins;
			else cost = min(cost, N-n+ins);
			//cerr << cost << endl;
			if(A - 1 > 0) {
				//insert
				while(A <= X[n]) {
					A += A - 1;
					ins++;
				}
				A += X[n];
			}
			else {
				ins = cost;
				break;
			}
		}
	}
	cost = min(cost, ins);
	cout << cost << endl;
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
