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

#define MAX 5000
double dp[MAX][MAX];
int main() {
	dp[0][0] = 1.0;
	REP(i, MAX - 1) REP(j, i + 1) {
		dp[i+1][j+1] += dp[i][j] * 0.5;
		dp[i+1][j] += dp[i][j] * 0.5;
	}
	
	int tc;
	cin >> tc;
	FOR(atc,1,tc+1) {
		int n,x,y;
		cin >> n >> x >> y;
		int lv = (abs(x) + y) / 2;
		int h = y;
		int olv = lv;
		
		double rv;
		if (lv == 0) {
			rv = 1;
		} else {
			n--;
			int s = 5;
			lv--;
			while (lv) {
				n -= s;
				s += 4;
				lv--;
			}
			if (n <= 0) {
				rv = 0;
			} else if (n >= s) {
				rv = 1;
			} else if (h == olv*2) {
				rv = 0;
			} else {
				rv = 0;
				h++;
				REP(i, n+1) if (h <= max(n-i-2*olv,0)+i) rv += dp[n][i];
			}
		}
		
		printf("Case #%d: %.9f\n", atc, rv);
	}
}
