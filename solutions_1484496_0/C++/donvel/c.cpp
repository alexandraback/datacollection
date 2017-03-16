#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
//#define DEBUG
#ifdef DEBUG
	#define DEB printf
#else
	#define DEB(...)
#endif
#define VAR(x, v) __typeof(v) x = (v)
#define REP(x, n) for(int x = 0; x < (n); x++)
#define FOR(x, b, e) for(int x = (b); x <= (e); x++)
#define FORD(x, u, d) for(int x = (u); x >= (d); x--)
#define FOREACH(x, v) for(VAR(x, (v).begin()); x != (v).end(); x++)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define MIN(a, b) (a) < (b) ? (a) : (b)
#define MAX(a, b) (a) > (b) ? (a) : (b)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long double LD;

const int N = 500, M = 100000 * 20 + 1;

int t, n;

int s;
int last[M];

void write(int v) {
	while(v != 0) {
		printf("%d ", last[v]);
		v -= last[v];
	}
}

int main() {
	scanf("%d", &t);
	REP(xx, t) {
		scanf("%d", &n);
		bool good = 0;
		REP(i, M) last[i] = 0;
		last[0] = -1;

		printf("Case #%d:\n", xx + 1);
		
		REP(i, n) {
			scanf("%d", &s);
			if(!good) FORD(i, M - 1, 0) if(last[i] && i + s < M) {
				if(last[i + s]) {
					good = 1;
					DEB("i + s = %d\n", i + s);
					write(i + s);
					printf("\n");
					printf("%d ", s);
					write(i);
					printf("\n");
					break;
				}
				last[i + s] = s;
			}
		}
		

		if(!good) {
			printf("Impossible\n");
		}

	}
	return 0;
}

