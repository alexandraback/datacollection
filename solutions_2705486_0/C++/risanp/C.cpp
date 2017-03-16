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

#define MAXLENGTHDICT 10

int nTC;

FILE *fdict;

#define MAXS 4000
#define MAXDICT 521196

int N;
char s[MAXS + 5];
int dp[MAXS + 5][7];
vector <int> BMS[11];
string dict[MAXDICT + 5];
int nDict;
int dsz[MAXDICT + 5];

inline void initBMS() {
	FOR (K, 1, 10) {
		REP (bm, (1 << K)) {
			int last = -10;
			bool tmp = true;
			REP (i, K) {
				if (bm & (1 << i)) {
					if (i - last < 5) {
						tmp = false;
						break;
					}
					last = i;
				}
			}
			if (tmp) {
				BMS[K].PB(bm);
			}
		}
		// cout << "BMS[" << K << "] => " << SIZE(BMS[K]) << endl;
	}
}

int doDP(int i, int bef) {
	if (i == N) return 0;
	int &ret = dp[i][bef];
	if (ret != -1) return ret;
	ret = oo;
	REP (k, nDict) {
		if (dsz[k] > N - i) continue;
		bool tmp = true;
		int last = i - bef;
		int ctr = 0;
		
		REP (j, dsz[k]) {
			if (dict[k][j] != s[i + j]) {
				if (i + j - last < 5) {
					tmp = false;
					break;
				}
				last = i + j;
				ctr++;
			}
		}
		int candidate = doDP(i + dsz[k], MIN(i + dsz[k] - last, 5));
		if (tmp) {
			ret = MIN(ret, candidate + ctr);
		}
	}
	return ret;
}

inline void readDict() {
	fdict = fopen("garbled_email_dictionary.txt", "r");
	
	// int maxlength = 0;
	nDict = 0;
	while (fscanf(fdict, "%s", s) == 1) {
		dict[nDict] = s;
		dsz[nDict] = SIZE(dict[nDict]);
		nDict++;
		// maxlength = MAX(maxlength, (int)strlen(s));
	}
	// printf("maxlength = %d\n", maxlength);
	// printf("nDict = %d\n", nDict);
	fclose(fdict);
}

int main() {
	
	readDict();
	scanf("%d", &nTC);
	initBMS();
	FOR (tc, 1, nTC) {
		RESET(dp, -1);
		scanf("%s", s);
		N = strlen(s);
		int ret;
		ret = doDP(0, 5);
		printf("Case #%d: %d\n", tc, ret);
	}
	return 0;
}

