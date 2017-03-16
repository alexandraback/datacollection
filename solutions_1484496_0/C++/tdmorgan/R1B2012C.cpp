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

#define MAX_TIME (3 * 60)

int x[505];

int main () {
	int T;
	scanf("%d", &T);
	FOR(itr, T) {
		cerr << itr << endl;

		int N;
		scanf("%d", &N);

		FOR(i, N)
			scanf("%d", x+i);

		printf("Case #%d:\n", itr+1);
		double start = getTime();
		bool success = false;
		while (getTime() - start < MAX_TIME / T) {
			int owner[N];
			int sum[3] = {0, 0, 0};
			FOR(i, N) {
				owner[i] = rand() % 3;
				sum[owner[i]] += x[i];
			}
			if (sum[0] == 0 || sum[1] == 0)
				continue;

			while (1) {
				int den = 1;
				int bv = INF;
				int bi = -1, bo = -1;
				FOR(i, N) {
					if (sum[owner[i]] == x[i]) // don't take away last
						continue;
					sum[owner[i]] -= x[i];
					FOR(o, 3) {
						if (owner[i] == o)
							continue;
						sum[o] += x[i];
						int v = abs(sum[0] - sum[1]);
						if (v < bv || (v == bv && rand() % den++ == 0)) {
							if (v == bv)
								den = 2;
							else
								bv = v;
							bi = i;
							bo = o;
						}
						sum[o] -= x[i];
					}
					sum[owner[i]] += x[i];
				}
				if (bv >= abs(sum[0] - sum[1]))
					break;
				sum[owner[bi]] -= x[bi];
				sum[bo] += x[bi];
				owner[bi] = bo;
			}

			if (sum[0] == sum[1]) {
				success = true;
				FOR(j, 2) {
					FOR(i, N)
						if (owner[i] == j)
							printf("%d ", x[i]);
					printf("\n");
				}
				break;
			}
		}
		if (!success)
			printf("Impossible\n");
	}
}
