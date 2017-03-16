#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
//#include <emmintrin.h>

using namespace std;

#define FOR(i,a,b)  for(int i=(a);i<(b);++i)
#define REP(i,a)    FOR(i,0,a)
#define ZERO(m)    memset(m,0,sizeof(m))
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define S          size()
#define LL          long long
#define ULL        unsigned long long
#define LD          long double
#define MP          make_pair
#define X          first
#define Y          second
#define VC          vector
#define PII        pair <int, int>
#define VI          VC < int >
#define VVI        VC < VI >
#define VD          VC < double >
#define VVD        VC < VD >
#define VS          VC < string >
#define DB(a)      cerr << #a << ": " << (a) << endl;

template<class T> void print(VC < T > v) {cerr << "[";if (v.S) cerr << v[0];FOR(i, 1, v.S) cerr << ", " << v[i];cerr << "]n";}
template<class T> string i2s(T x) {ostringstream o; o << x; return o.str(); }
VS splt(string s, char c = ' ') {VS all; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) all.PB(s.substr(p, np - p)); p = np + 1;} if (p < s.S) all.PB(s.substr(p)); return all;}


int main() {
	int tc;
	cin >> tc;
	FOR(atc,1,tc+1) {
		LL x;
		cin >> x;
		int rv = 1 << 25;
		int n;
		cin >> n;
		VI v(n);
		REP(i, n) cin >> v[i];
		sort(ALL(v));
		int no = 0;
		REP(i, n) {
			rv = min(rv, no + (n - i));
			if (x == 1) break;
			while (x <= v[i]) {
				x += x - 1;
				no++;
			}
			x += v[i];
			rv = min(rv, no + (n - i - 1));
		}
		printf("Case #%d: %d\n", atc, rv);
	}
	return 0;
}