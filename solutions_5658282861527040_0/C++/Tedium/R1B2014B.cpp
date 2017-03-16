#include <list>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <ext/hash_map>
#include <stdint.h>
#include <ctime>
#include <queue>
#include <sstream>
#include <sys/time.h>
#include <fstream>
#include <vector>

using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef long long LL;
typedef unsigned char BYTE;

#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define FORU(i, s, e) for (int i = (s); i <= (e); ++i)
#define FORD(i, s, e) for (int i = (s); i >= (e); --i)
#define ALL(x) x.begin(),x.end()
#define FOREACH(i, v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define SIZE(x) ((int)x.size())
#define MP make_pair
#define PB push_back
#define BIT(x, b) (((x) >> (b)) & 1)
#define SWAP(a, b, t) do {t = a; a = b; b = t;} while (0);
#define INF 1000000000
#define EPS 1e-9
#define TIME_LEFT_UNTIL(end) ((curTime=getTime()-startTime) < (end))
#define TIME_LEFT() TIME_LEFT_UNTIL(MAX_TIME)
#define INIT_TIME() startTime = getTime()

inline double getTime () {
   timeval tv;
   gettimeofday(&tv, 0);
   return tv.tv_sec + tv.tv_usec * 1e-6;
}

int A, B, K;
LL mem[31][2][2][2];

LL dfs (int bit, bool am, bool bm, bool km) {
	if (bit < 0)
		return 1;

	if (mem[bit][am][bm][km] >= 0)
		return mem[bit][am][bm][km];

	LL out = 0;
	FOR(a, 2) {
		if (a == 1 && am && BIT(A, bit) == 0)
			continue;
		FOR(b, 2) {
			if (b == 1 && bm && BIT(B, bit) == 0)
				continue;
			if ((a & b) == 1 && km && BIT(K, bit) == 0)
				continue;
			out += dfs(bit-1, am & (a == BIT(A, bit)), bm & (b == BIT(B, bit)), km & ((a & b) == BIT(K, bit)));
		}
	}
	return mem[bit][am][bm][km] = out;
}

int main () {
	int T;
	scanf("%d", &T);
	FOR(itr, T) {
		scanf("%d%d%d", &A, &B, &K);
		--A; --B; --K;

		FOR(i, 31)
			FOR(j, 2)
				FOR(k, 2)
					FOR(m, 2)
						mem[i][j][k][m] = -1;

		cout << "Case #" << itr+1 << ": " << dfs(30, 1, 1, 1) << endl;
	}
}
