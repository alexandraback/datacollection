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
typedef vector<int>     VI;
typedef vector<LL>      VL;
typedef vector<PII>     VPII;
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
template<class A, class B> ostream& operator<<(ostream &o, pair<A, B> t) {o << "(" << t.x << ", " << t.y << ")"; return o;}
template<class T> void PV(T a, T b) {while(a != b)cout << *a++, cout << (a != b ? " " : "\n");}
template<class T> inline bool chmin(T &a, T b) {return a > b ? a = b, 1 : 0;}
template<class T> inline bool chmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template<class T> string tostring(T x, int len = 0) {stringstream ss; ss << x; string r = ss.str(); if(r.length() < len) r = string(len - r.length(), '0') + r; return r;}
template<class T> void convert(string x, T& r) {stringstream ss(x); ss >> r;}
const int inf = 0x3f3f3f3f;
const long long linf = 0x3f3f3f3f3f3f3f3fLL;
const int mod = int(1e9) + 7;
const int N = 111111;

int main() {
	int T;
	cin >> T;
	for(int ts = 1; ts <= T; ts++) {
		int n;
		vector<string> vs;
		vector<int> p;
		cin >> n;
		for(int i = 0; i < n; i++) {
			string s;
			cin >> s;
			vs.pb(s);
			p.pb(i);
		}

		cout << "Case #" << ts << ": ";

		LL res = 0;
		int c = 0;
		int L[26];
		int R[26];
		do {
			string s;
			for(int i = 0; i < n; i++) s += vs[p[i]];
			MM(L, 0);
			MM(R, -1);
			for(int i = 0; i < s.length(); i++) R[s[i] - 'a'] = i;
			for(int i = s.length() - 1; i >= 0; i--) L[s[i] - 'a'] = i;
			int tot = 0;
			for(int i = 0; i < 26; i++) tot += R[i] - L[i] + 1;
			if(tot == s.length()) res++;
		} while(next_permutation(ALL(p)));
		cout << res << endl;
	}
	return 0;
}
