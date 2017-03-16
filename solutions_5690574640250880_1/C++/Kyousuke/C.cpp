//Magic Trick
//g++ --std=c++11 -W -Wall -Wno-sign-compare -O2 -s -pipe -mmmx -msse -msse2 -msse3
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

void gcjmain() {
	int R, C, M;
	cin >> R >> C >> M;
	int l = max(R, C), s = min(R, C);
	if(R*C-1 == M) {
		forl(r, 0, R) {
			forl(c, 0, C) {
				if(r==0 && c==0) cout << 'c';
				else cout << '*';
			}
			cout << endl;
		}
	}
	else if(M == 0) {
		forl(r, 0, R) {
			forl(c, 0, C) {
				if(r==0 && c==0) cout << 'c';
				else cout << '.';
			}
			cout << endl;
		}
	}
	else if(s == 1) {
		forl(r, 0, R) {
			forl(c, 0, C) {
				if(M>0) {cout << '*'; M--;}
				else if(r==R-1&&c==C-1) cout << 'c';
				else cout << '.';
			}
			cout << endl;
		}
	}
	else {
		vector< vector<char> > grid(s, vector<char>(l, '*'));
		int open = R*C - M;
		int first = min(l, open/2);
		if(open - first*2 == 1) first--;
		if(first < 2 || (first == 2 && open - 2*first == 3)) cout << "Impossible" << endl;
		else {
			int left = open;
			int prev = 0;
			forl(r, 0, s) {
				int cur = 0;
				forl(c, 0, l) {
					if(r==0 && c==0) {grid[r][c] = 'c'; left--; cur++;}
					else if(r < 2 && c < first) {grid[r][c] = '.'; left--; cur++;}
					else if(r >= 2 && ((left>0 && left <= prev-c) || left > 2)) {grid[r][c] = '.'; left--; cur++;}
				}
				if(cur != 0) prev = cur;
			}
			if(prev == 1 || left) cout << "Impossible" << endl;
			else {
				forl(r, 0, R) {
					forl(c, 0, C) {
						if(C < R) cout << grid[c][r];
						else cout << grid[r][c];
					}
					cout << endl;
				}
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	forl(t, 1, T+1) {
		cerr << "Case: " << t << '/' << T << endl;
		cout << "Case #" << t << ":\n";
		gcjmain();
	}
}
