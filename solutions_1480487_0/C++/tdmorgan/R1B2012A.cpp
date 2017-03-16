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

static inline double getTime () {
   timeval tv;
   gettimeofday(&tv, 0);
   return tv.tv_sec + tv.tv_usec * 1e-6;
}

int x[222];

int main () {
	int T;
	scanf("%d", &T);
	FOR(itr, T) {
		int N;
		scanf("%d", &N);
		int sum = 0;
		FOR(i, N) {
			scanf("%d", x+i);
			sum += x[i];
//			cerr << "(" << x[i] << ", " << sum << ") ";
		}
//		cerr << endl;

		printf("Case #%d:", itr+1);

		FOR(i, N) {
			double low = 0, high = 1;
			while (high - low > 1e-8) {
				double mid = (low + high) / 2;

				double val = x[i] + sum * mid;
				double left = 1 - mid;
				FOR(j, N) {
					if (j == i)
						continue;
					if (x[j] >= val)
						continue;
					left -= (val - x[j]) / sum;
				}
//				cerr << low << " " << high << " " << val << " " << left << endl;
				if (left <= 0)
					high = mid;
				else
					low = mid;
			}
			printf(" %.6f", 50 * (low + high));
		}

		printf("\n");
	}
}
