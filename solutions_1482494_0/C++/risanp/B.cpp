#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <ctime>

#define oo 1000000005
#define eps 1e-11

#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define FOREACH(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define RESET(c,x) memset (c, x, sizeof (c))

#define sqr(x) ((x) * (x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()

using namespace std;

const double PI = 2.0 * acos (0.0);

typedef long long LL;
typedef pair <int, int> PII;

inline int getInt () { int x; scanf ("%d", &x); return x; }
inline LL getLL () { LL x; scanf ("%lld", &x); return x; };
inline int NUM (char c) { return (int)c - 48; }
inline char CHR (int n) { return (char)(n + 48); }
template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }
template <class T> inline T ABS (T a) { if (a < 0) return -a; return a; }

inline void OPEN (string s) {
    freopen ((s + ".in").c_str (), "r", stdin);
    freopen ((s + ".out").c_str (), "w", stdout);
}

// ptrrsn_1's template

#define MAXN 1000

int N;
int A[MAXN + 5], B[MAXN + 5];
bool flag[MAXN + 5][2];
vector <PII> v;

int main () {
	OPEN("B");
	
	int nTC;
	cin >> nTC;
	
	FOR (tc, 1, nTC) {
		cin >> N;
		REP (i, N) cin >> A[i] >> B[i];
		v.clear();
		REP (i, N) v.PB(MP(B[i], A[i]));
		sort(ALL(v), greater <PII> ());
		REP (i, N) { A[i] = v[i].S, B[i] = v[i].F; }
		
		RESET(flag, 0);
		int point = 0, ret = 0;
		while (true) {
			ret++;
			bool found = false;
			REP (i, N) {
				if (B[i] <= point && !flag[i][1]) {
					if (!flag[i][0]) point += 2;
					else point += 1;
					flag[i][0] = flag[i][1] = true;
					found = true;
					break;
				}
			}
			if (found) continue;
			REP (i, N) {
				if (A[i] <= point && !flag[i][0]) {
					point++;
					flag[i][0] = true;
					found = true;
					break;
				}
			}
			if (!found) break;
		}
		ret--;
		
		REP (i, N) if (flag[i][1] == false) ret = -1;
		cout << "Case #" << tc << ": ";
		if (ret == -1) cout << "Too Bad" << endl;
		else cout << ret << endl;
	}
	
    return 0;
}
