//g++ --std=c++14 -Wall -Wno-sign-compare -O2 -s -march=native
#include <iostream>
#include <iterator>
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

#define forl(i, s, t) for(__typeof(s) i = s; i != t; i++)
#define rforl(i, s, t) for(__typeof(s) i = s; i != t; i--)

#define rep(n) forl(rep_c, 0, n)
#define fill2d_nn(g, s, z, v) forl(i, 0, s) fill_n(g[i], z, v)
#define fill2d_n(g, s, v) fill2d_nn(g, s, s, v)
//#define read(s, t) forl(read_c, s, t) cin >> *read_c
//inline void read(ForwardIterator s, ForwardIterator e) { forl(i, s, e) cin >> *i; }
//#define read_n(x, n) forl(read_n_c, 0, n) cin >> x[read_n_c]
//#define rread_n(x, n) rforl(rread_n_c, n-1, -1) cin >> x[rread_n_c]

#define tpop(x) (x).top(); (x).pop()
#define fpop(x) (x).front(); (x).pop()
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)

template<typename T> inline void chmin(T& a, const T& b) { a = min(a, b); }
template<typename T> inline void chmax(T& a, const T& b) { a = max(a, b); }

template<typename T> T gcd(T a, T b) { if(b == (T)0) return a; return gcd(b, a % b); }
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

const int INF = numeric_limits<int>::max()/2;
const double EPS = INF*numeric_limits<double>::epsilon();

int qrep(char c) {
	if(c == '1') return 1;
	if(c == 'i') return 2;
	if(c == 'j') return 3;
	if(c == 'k') return 4;
	return 0;
}

int quaternion(int a, int b) {
	if((a < 0 && b >= 0) || (a >= 0 && b < 0)) return -quaternion(-a, b);
	a = abs(a);
	b = abs(b);
	swap(a, b);
	if(a == 1) {
		if(b == 1) return 1;
		if(b == 2) return 2;
		if(b == 3) return 3;
		if(b == 4) return 4;
	} else if(a == 2) {
		if(b == 1) return 2;
		if(b == 2) return -1;
		if(b == 3) return -4;
		if(b == 4) return 3;
	} else if(a == 3) {
		if(b == 1) return 3;
		if(b == 2) return 4;
		if(b == 3) return -1;
		if(b == 4) return -2;
	} else if(a == 4) {
		if(b == 1) return 4;
		if(b == 2) return -3;
		if(b == 3) return 2;
		if(b == 4) return -1;
	}
	return 0;
}

void gcjmain() {
	int L, X;
	cin >> L >> X;
	vector< vector<int> > enc(L, vector<int>(L));
	string line;
	cin >> line;
	for(int i = 0; i < L; i++) {
		enc[i][i] = qrep(line[i]);
	}
	for(int i = 0; i < L; i++) {
		for(int j = i+1; j < L; j++) {
			enc[i][j] = quaternion(enc[i][j-1], qrep(line[j]));
		}
	}
	int req = 1;
	//Get i
	int icount = INF;
	for(int i = 0; i < L; i++) {
		if(enc[0][i] == 2) {
			chmin(icount, i+1);
		} else if(quaternion(enc[0][L-1], enc[0][i]) == 2) {
			chmin(icount, L + i+1);
		} else if(quaternion(quaternion(enc[0][L-1], enc[0][L-1]), enc[0][i]) == 2) {
			chmin(icount, 2*L + i+1);
		} else if(quaternion(quaternion(quaternion(enc[0][L-1], enc[0][L-1]), enc[0][L-1]), enc[0][i]) == 2) {
			chmin(icount, 3*L + i+1);
		}
	}
	if(icount == INF) {
		cout << "NO" << endl;
		//cerr << "missing i" << endl;
		return;
	}
	req += icount / L;
	//cerr << (icount / L) << "*" << line << "+" << (icount % L) << endl;
	if(req > X) {
		cout << "NO" << endl;
		//cerr << "not enough for i" << endl;
		return;
	}
	//Get k
	int kcount = INF;
	for(int i = L-1; i >= 0; i--) {
		if(enc[i][L-1] == 4) {
			chmin(kcount, L-i);
		} else if(quaternion(enc[i][L-1], enc[0][L-1]) == 4) {
			chmin(kcount, L + L-i);
		} else if(quaternion(enc[i][L-1], quaternion(enc[0][L-1], enc[0][L-1])) == 4) {
			chmin(kcount, 2*L + L-i);
		} else if(quaternion(enc[i][L-1], quaternion(quaternion(enc[0][L-1], enc[0][L-1]), enc[0][L-1])) == 4) {
			chmin(kcount, 3*L + L-i);
		}
	}
	if(kcount == INF) {
		cout << "NO" << endl;
		//cerr << "missing k" << endl;
		return;
	}
	req += kcount / L;
	//cerr << (kcount / L) << "*" << line << "+" << (kcount % L) << endl;
	if(req > X) {
		cout << "NO" << endl;
		//cerr << "not enough for k" << endl;
		return;
	}
	//Check j
	int mod = 4;
	if(enc[0][L-1] == 1) mod = 1;
	else if(quaternion(enc[0][L-1], enc[0][L-1]) == 1) mod = 2;
	int start = icount % L;
	int end = L - 1 - kcount % L;
	//cerr << "looking for j in [" << start << "," << end << "] with " << X - req << " remaining repeats" << endl;
	if(end >= start && enc[start][end] == 3 && (X - req) % mod == 0) {
		cout << "YES" << endl;
		return;
	}
	forl(i, 0, 5) {
		req++;
		if(req > X) {
			cout << "NO" << endl;
			//cerr << "not enough for j" << endl;
			return;
		}
		int val = enc[start][L-1];
		forl(j, 0, i) {
			val = quaternion(val, enc[0][L-1]);
		}
		if(quaternion(val, enc[0][end]) == 3 && (X - req) % mod == 0) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
	//cerr << "missing j" << endl;
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
