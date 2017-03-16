#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <assert.h>
#include <math.h>
#include <string.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
#define FOREACH(it,vec) for(typeof((vec).begin()) it = (vec).begin(); it != (vec).end(); it++)
#define MOD(a,b) (((a)%(b)+(b))%(b))
#define REP(i,n) for (int i = 0; i < (n); i++)

int T;
int X, Y;
int f[200][200];

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		scanf("%d%d", &Y, &X);
		REP(y,Y) REP(x,X)
			scanf("%d", &f[x][y]);
		bool works = true;
		REP(h,101) {
			REP(x,X) {
				bool ok = true;
				REP(y,Y)
					if (f[x][y] > h)
						ok = false;
				if (ok)
					REP(y,Y)
						f[x][y] = 0;
			}
			REP(y,Y) {
				bool ok = true;
				REP(x,X)
					if (f[x][y] > h)
						ok = false;
				if (ok)
					REP(x,X)
						f[x][y] = 0;
			}
			REP(x,X)
				REP(y,Y)
					if (f[x][y] == h)
						works = false;
		}
		printf(works ? "YES\n" : "NO\n");
	}
	return 0;
}
