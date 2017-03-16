#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <cassert>

#define oo 1000111000

#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define FOREACH(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)

#define PB push_back
#define MP make_pair
#define SIZE(c) (c).size()
#define ALL(c) (c).begin(), (c).end()
#define RESET(c,x) memset(c,x,sizeof(c))
#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <class T> inline T MAX(T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN(T a, T b) { if (a < b) return a; return b; }
template <class T> inline T ABS(T x) { if (x < 0) return -x; return x; }

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

// template by ptrrsn_1

#define MAXN 100

int nTC;
LL K;
int N;
LL A[MAXN + 5];

int main() {
	int nTC;
	scanf("%d", &nTC);
	
	FOR (tc, 1, nTC) {
		scanf("%lld%d", &K, &N);
		REP (i, N) scanf("%lld", &A[i]);
		sort(A, A + N);
		int ret = N;
		FOR (i, 1, N) {
			int ctr = N - i;
			LL X = K;
			REP (j, i) {
				while (X <= A[j]) {
					X += X - 1;
					ctr++;
					if (ctr >= ret) break;
				}
				if (ctr >= ret) break;
				X += A[j];
			}
			// cout << "ctr = " << ctr << endl;
			ret = MIN(ret, ctr);
		}
		printf("Case #%d: %d\n", tc, ret);
	}
	
	return 0;
}

