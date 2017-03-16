#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long       LL;
typedef pair<int, int>  PII;
typedef pair<LL, LL>    PLL;
typedef vector<int>     VI;
typedef vector<LL>      VL;
typedef vector<PII>     VPII;
typedef vector<PLL>     VPLL;
#define MM(a,x) memset(a,x,sizeof(a));
#define ALL(x)  (x).begin(), (x).end()
#define P(x)	cerr<<"["#x<<" = "<<(x)<<"]\n"
#define PP(x,i)	cerr<<"["#x<<i<<" = "<<x[i]<<"]\n"
#define P2(x,y)	cerr<<"["#x" = "<<(x)<<", "#y" = "<<(y)<<"]\n"
#define TM(a,b)	cerr<<"["#a" -> "#b": "<<1e3*(b-a)/CLOCKS_PER_SEC<<"ms]\n";
#define UN(v) sort(ALL(v)), v.resize(unique(ALL(v))-v.begin())
#define mp make_pair
#define pb push_back
#define x first
#define y second
struct _ {_() {ios_base::sync_with_stdio(0);}} _;
template<class T> void PV(T a, T b) {while(a != b)cout << *a++, cout << (a != b ? " " : "\n");}
template<class T> inline bool chmin(T &a, T b) {return a > b ? a = b, 1 : 0;}
template<class T> inline bool chmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template<class T> string tostring(T x, int len = 0) {stringstream ss; ss << x; string r = ss.str(); if(r.length() < len) r = string(len - r.length(), '0') + r; return r;}
template<class T> void convert(string x, T& r) {stringstream ss(x); ss >> r;}
template<class A, class B> ostream& operator<<(ostream &o, pair<A, B> t) {o << "(" << t.x << ", " << t.y << ")"; return o;}
const int inf = 0x3f3f3f3f;
const int mod = int(1e9) + 7;
const int N = 111111;

int main() {
	int T;
	cin >> T;
	for(int ts = 1; ts <= T; ts++) {
		int n;
		cin >> n;
		vector<int> a, b;
		for(int i = 0; i < n; i++) {
			double t;
			cin >> t;
			t *= 1e6;
			a.pb(int(t + 1e9));
		}
		for(int i = 0; i < n; i++) {
			double t;
			cin >> t;
			t *= 1e6;
			b.pb(int(t + 1e9));
		}
		sort(ALL(a));
		sort(ALL(b));
		vector<int> v = a;
		for(auto i : b) v.pb(i);
		UN(v);
		map<int, int> M;
		for(int i = 0; i < v.size(); i++) M[v[i]] = i;
		for(auto& i : a) i = M[i];
		for(auto& i : b) i = M[i];
		int pi = 0, pj = 0;
		int res1 = 0;
		int res2 = 0;
		while(1) {
			while(pj < n && a[pi] > b[pj]) pj++;
			if(pj == n) break;
			res2++;
			pi++, pj++;
		}
		res2 = n - res2;

		while(!a.empty()) {
			if(!a.empty() && *a.rbegin() > *b.rbegin()) {
				a.erase(lower_bound(ALL(a), *b.begin()));
				b.erase(b.begin());
				res1++;
			}
			if(!a.empty() && *a.rbegin() < *b.rbegin()) {
				a.erase(a.begin());
				b.pop_back();
			}
		}
		cout << "Case #" << ts << ": ";
		cout << res1 << " " << res2 << endl;
	}


	return 0;
}
