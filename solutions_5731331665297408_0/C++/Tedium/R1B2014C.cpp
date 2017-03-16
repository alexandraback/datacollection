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

int N, M;
int v[55];
bool adj[55][55];
bool vis[55];
bool reached[55];
bool returned[55];
int order[55];

int dfs (int x) {
	if (vis[x])
		return 0;

	int out = 1;
	vis[x] = 1;
	FOR(i, N)
		if (adj[x][i])
			out += dfs(i);
	return out;
}

bool canFinish (VI path, int peelTo) {
	FOR(i, N)
		vis[i] = returned[i];
	FOR(i, SIZE(path))
		vis[path[i]] = 1;

	FORD(i, peelTo, 0) {
		vis[path[i]] = 0;
		dfs(path[i]);
	}

	FOR(i, N)
		if (!vis[i])
			return 0;
	return 1;
}

int main () {
	int T;
	scanf("%d", &T);
	FOR(itr, T) {
		scanf("%d%d", &N, &M);
		FOR(i, N)
			scanf("%d", v+i);
		FOR(i, N)
			FOR(j, N)
				adj[i][j] = 0;
		FOR(i, M) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u-1][v-1] = 1;
			adj[v-1][u-1] = 1;
		}

		FOR(i, N)
			order[i] = i;
		FORU(i, 1, N-1)
			for (int j = i-1; j >= 0 && v[order[j]] > v[order[j+1]]; --j) {
				int t;
				SWAP(order[j], order[j+1], t);
			}

		int start = -1;
		FOR(i, N) {
			FOR(j, N)
				vis[j] = 0;
			if (dfs(order[i]) == N) {
				start = order[i];
				break;
			}
		}
//		cerr << start << endl;

		printf("Case #%d: %d", itr+1, v[start]);
		VI path;
		path.PB(start);
		FOR(j, N) {
			reached[j] = 0;
			returned[j] = 0;
		}
		reached[start] = 1;
		int count = 1;

		while (count < N) {
//			cerr << count << endl;
			FOR(i, N)
				if (!reached[order[i]]) {
					if (adj[path[SIZE(path)-1]][order[i]]) {
						++count;
						reached[order[i]] = 1;
						path.PB(order[i]);
						printf("%d", v[order[i]]);
						break;
					}
					else if (SIZE(path) > 1) {
						bool success = 0;
						FORD(j, SIZE(path)-2, 0)
							if (adj[path[j]][order[i]] && canFinish(path, j)) {
								success = 1;
								while (SIZE(path) > j+1) {
									returned[path[SIZE(path)-1]] = 1;
									path.pop_back();
								}
								++count;
								reached[order[i]] = 1;
								path.PB(order[i]);
								printf("%d", v[order[i]]);
								break;
							}
						if (success)
							break;
					}
				}
		}
		printf("\n");
	}
}
