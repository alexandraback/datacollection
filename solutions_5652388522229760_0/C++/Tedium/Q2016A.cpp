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

int main () {
	double time = getTime();

	int T;
	scanf("%d", &T);
	FOR(itr, T) {
		int _N;
		scanf("%d", &_N);

		int u = 0;
		LL N = _N;
		LL out = -1;
		FORU(i, 1, 1000000) {
			LL x = i * N;
			while (x > 0) {
				u |= 1 << (x % 10);
				x /= 10;
			}
			if (u == (1 << 10) - 1) {
				out = i * N;
				break;
			}
		}

		if (out == -1)
			printf("Case #%d: INSOMNIA\n", itr+1);
		else
			printf("Case #%d: %lld\n", itr+1, out);
		fflush(stdout);
	}

	cerr << "time: " << getTime() - time << endl;
}
