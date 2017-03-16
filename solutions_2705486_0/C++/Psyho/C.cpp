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

VS v1;
VS v2;
VS v3[26][26][26];

int dp[5000][5];
int main() {
	FILE *f = fopen("dict.txt", "r");
	while (!feof(f)) {
		char buf[100];
		int no = fscanf(f,"%s",buf);
		if (no == 0) break;
		string s(buf);
		if (s.S == 1) v1.PB(s);
		if (s.S == 2) v2.PB(s);
		if (s.S >= 3) {
			v3[s[0]-'a'][s[1]-'a'][s[2]-'a'].PB(s);
			FOR(c,'a','z'+1) {
				if (c!=s[0]) v3[c-'a'][s[1]-'a'][s[2]-'a'].PB(s);
				if (c!=s[1]) v3[s[0]-'a'][c-'a'][s[2]-'a'].PB(s);
				if (c!=s[2]) v3[s[0]-'a'][s[1]-'a'][c-'a'].PB(s);
			}
		}
	}
	
	int tc;
	cin >> tc;
	FOR(atc, 1, tc + 1) {
		string s;
		cin >> s;
		REP(i, 5000) REP(j, 5) dp[i][j] = 1 << 20;
		dp[0][0] = 0;
		
		REP(i, s.S) REP(j, 5) {
			REP(k, v1.S) {
				if (s[i] == v1[k][0]) dp[i+1][max(0,j-1)] = min(dp[i+1][max(0,j-1)], dp[i][j]);
				if (s[i] != v1[k][0] && j == 0) dp[i+1][4] = min(dp[i+1][4], dp[i][j]+1);
			}
			if (i + 1 < s.S) {
				REP(k, v2.S) {
					if (s[i] == v2[k][0] && s[i+1] == v2[k][1]) dp[i+2][max(0,j-2)] = min(dp[i+2][max(0,j-2)], dp[i][j]);
					if (s[i] == v2[k][0] && s[i+1] != v2[k][1] && j <= 1) dp[i+2][4] = min(dp[i+2][4], dp[i][j]+1);
					if (s[i] != v2[k][0] && s[i+1] == v2[k][1] && j <= 0) dp[i+2][3] = min(dp[i+2][3], dp[i][j]+1);
				}
			}
			if (i + 2 < s.S) {
				VS &v = v3[s[i]-'a'][s[i+1]-'a'][s[i+2]-'a'];
				REP(k, v.S) if (i + v[k].S <= s.S) {
					int lp = j - 5;
					int no = 0;
					bool ok = true;
					REP(l, v[k].S) if (v[k][l] != s[i+l]) {
						if (l <= lp + 4) {
							ok = false;
							break;
						}
						no++;
						lp = l;
					}
					if (!ok) continue;
					dp[i+v[k].S][max(0,5-((int)v[k].S-lp))] = min(dp[i+v[k].S][max(0,5-((int)v[k].S-lp))],dp[i][j]+no);
				}
			}
		}
		
		int rv = 1 << 20;
		REP(i, 5) rv = min(rv, dp[s.S][i]);
		printf("Case #%d: %d\n", atc, rv);
	}
	
	return 0;
}