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
#define MODD(a,b) (((a)%(b)+(b))%(b))
#define REP(i,a,n) for (int i = (a); i < (n); i++)

int T, X, Y, M, W;
bool open[100][100];

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d:\n", test+1);
		scanf("%d%d%d", &Y, &X, &M);
		W = X*Y-M;
		bool ok = true;
		if (X == 1) {
			REP(y,0,Y)
				open[0][y] = (y < W);
		} else if (Y == 1) {
			REP(x,0,X)
				open[x][0] = (x < W);
		} else if (W == 1) {
			REP(x,0,X) REP(y,0,Y)
				open[x][y] = (x == 0 && y == 0);
		} else {
			ok = false;
			for (int a = 2; a <= X && !ok; a++)
			for (int b = 2; b <= Y && !ok; b++) {
				if (2*(a+b-2) <= W && W <= a*b) {
					ok = true;
					REP(x,0,X) REP(y,0,Y)
						open[x][y] = (x < a && y < b && (x < 2 || y < 2 || 2*(a+b-2) + (x-2)*(b-2)+y-2+1 <= W));
				}
			}
		}
		if (ok) {
			REP(y,0,Y) {
				REP(x,0,X) {
					if (x == 0 && y == 0)
						printf("c");
					else if (open[x][y])
						printf(".");
					else
						printf("*");
				}
				printf("\n");
			}
		} else {
			printf("Impossible\n");
			if (X != 2 && Y != 2 && W >= 8)
				fprintf(stderr, "ERR\n");
		}
	}
	return 0;
}
