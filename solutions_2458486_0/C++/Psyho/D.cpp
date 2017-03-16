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

int dp[1<<20];
map<int, int> sk;
int lock[20];
VI lk[20];
int main() {
	int tc;
	cin >> tc;
	FOR(atc, 1, tc + 1) {
		printf("Case #%d: ", atc);
		sk.clear();
		
		int k, n;
		cin >> k >> n;
		REP(i, k) {
			int x;
			cin >> x;
			sk[x] = sk[x] + 1;
		}
		
		REP(i, n) {
			cin >> lock[i];
			int z;
			cin >> z;
			lk[i].clear();
			REP(j, z) {
				int x;
				cin >> x;
				lk[i].PB(x);
			}
		}
		
		dp[(1<<n)-1] = 1;
		for (int i = (1<<n) - 2; i >= 0; i--) {
			dp[i] = 0;
			map<int, int> ck(ALL(sk));
			REP(j, n) if (i & (1 << j)) {
				ck[lock[j]] = ck[lock[j]] - 1;
				REP(k, lk[j].S) ck[lk[j][k]] = ck[lk[j][k]] + 1;
			}
			// cout << i << ":";
			// for (map<int, int>::iterator it = ck.begin(); it != ck.end(); it++)
				// cout << ' ' << it->X << '-' << it->Y;
			// cout << endl;
			REP(j, n) if ((i & (1 << j)) == 0 && ck[lock[j]] > 0) {
				dp[i] |= dp[i | (1 << j)];
			}
		}
		
		if (dp[0] == 0) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			int state = 0;
			REP(i, n) {
				map<int, int> ck(ALL(sk));
				REP(j, n) if (state & (1 << j)) {
					ck[lock[j]] = ck[lock[j]] - 1;
					REP(k, lk[j].S) ck[lk[j][k]] = ck[lk[j][k]] + 1;
				}
				REP(j, n) if ((state & (1 << j)) == 0 && dp[state | (1 << j)] == 1 && ck[lock[j]] > 0) {
					if (i) cout << ' ';
					cout << (j + 1);
					state |= 1 << j;
					break;
				}
			}
			cout << endl;
		}
	}
	return 0;
}