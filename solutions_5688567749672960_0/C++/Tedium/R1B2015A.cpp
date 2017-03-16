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

#define MAXN 1234567

bool vis[MAXN];
int flip[MAXN];

int bfs (int N) {
	if (N == 1)
		return 1;

	FORU(i, 0, N)
		vis[i] = 0;
	vis[1] = 1;

	int cur = 1;
	VI *cq, *nq;
	cq = new VI();
	nq = new VI();
	cq->PB(1);

	while (1) {
		FOREACH(vi, *cq) {
			int i = *vi;
			if (i+1 < MAXN && !vis[i+1]) {
				if (i+1 == N)
					return cur+1;
				vis[i+1] = 1;
				nq->PB(i+1);
			}
			int f = flip[i];
			if (f < MAXN && !vis[f]) {
				if (f == N)
					return cur+1;
				vis[f] = 1;
				nq->PB(f);
			}
		}
		++cur;
		free(cq);
		cq = nq;
		nq = new VI();
	}
}

int main () {
	double time = getTime();


	FOR(i, MAXN) {
		int flipped = 0;
		int p = 1;
		while (p <= i)
			p *= 10;
		p /= 10;
		int p2 = 1;
		while (p > 0) {
			flipped += p2 * ((i / p) % 10);
			p /= 10;
			p2 *= 10;
		}
		flip[i] = flipped;
//		if (i < 20) {
//			cerr << i << " " << flipped << endl;
//		}
	}

	int T;
	scanf("%d", &T);
	FOR(itr, T) {
		int N;
		scanf("%d", &N);

		int out = bfs(N);
		printf("Case #%d: %d\n", itr+1, out);
	}
	cerr << getTime() - time << endl;
}
