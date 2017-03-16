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

#define MAXN 100000
double P[MAXN + 5];

int main () {
	OPEN("A");
	
	int nTC;
	cin >> nTC;
	
	FOR (tc, 1, nTC) {
		int A, B;
		cin >> A >> B;
		
		REP (i, A) cin >> P[i];
		
		double E = 1e50;
		// 1. didn't delete at all
		double mult = 1.0;
		REP (i, A) mult *= P[i];
		E = mult * (B + 1) + (1 - mult) * (2 * B + 2);
		
		// 2
		mult = 1.0;
		REP (i, A) {
			// delete A-i chars
			int del = A - i;
			E = MIN(E, mult * (B + 2 * del + 1) + (1 - mult) * (2 * B + 2 * del + 2));
			mult *= P[i];
		}
		
		// 3
		mult = 1.0;
		E = MIN(E, A + B + 2.0);
		
		cout << "Case #" << tc << ": ";
		printf("%.8lf\n", E - A);
	}
	
    return 0;
}
