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

int R, C, M;

int main () {
	int T;
	scanf("%d", &T);
	FOR(itr, T) {
		scanf("%d%d%d", &R, &C, &M);
		int E = R * C - M;

		char out[R][C];
		FOR(i, R)
			FOR(j, C)
				out[i][j] = '*';

		bool success = 0;
		if (E > 0) {
			if (R == 1) {
				success = 1;
				FOR(i, E)
					out[0][i] = '.';
			}
			else if (C == 1) {
				success = 1;
				FOR(i, E)
					out[i][0] = '.';
			}
			else if (E == 1) {
				success = 1;
				out[0][0] = '.';
			}
			else {
				FORD(i, min(C, E / 2), 2) {
					int left = E - 2 * i;
					if ((i > 2 && (left == 0 || (left > 1 && R >= 2 + ((left + i-1) / i)))) ||
						(i == 2 && left % 2 == 0 && 2 * R >= E)) {
						success = 1;
						left = E;
						FOR(r, R) {
							int thisRow = min(i, left);
							if (left - thisRow == 1)
								--thisRow;
							FOR(c, thisRow)
								out[r][c] = '.';
							left -= thisRow;
							if (left == 0)
								break;
						}
						break;
					}
				}
			}
			out[0][0] = 'c';
		}

		printf("Case #%d:\n", itr+1);
		if (!success)
			printf("Impossible\n");
		else {
			FOR(i, R) {
				FOR(j, C)
					printf("%c", out[i][j]);
				printf("\n");
			}
		}
	}
}
