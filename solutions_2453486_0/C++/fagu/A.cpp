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
char f[10][10];

bool won(char c) {
	REP(y,4) {
		bool fo = false;
		REP(x,4)
			if (f[y][x] != c && f[y][x] != 'T')
				fo = true;
		if (!fo)
			return true;
	}
	REP(x,4) {
		bool fo = false;
		REP(y,4)
			if (f[y][x] != c && f[y][x] != 'T')
				fo = true;
		if (!fo)
			return true;
	}
	{
		bool fo = false;
		REP(k,4)
			if (f[k][k] != c && f[k][k] != 'T')
				fo = true;
		if (!fo)
			return true;
	}
	{
		bool fo = false;
		REP(k,4)
			if (f[k][3-k] != c && f[k][3-k] != 'T')
				fo = true;
		if (!fo)
			return true;
	}
	return false;
}

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		REP(y,4)
			scanf("%s ", f[y]);
		if (won('X'))
			printf("X won\n");
		else if (won('O'))
			printf("O won\n");
		else {
			bool fo = false;
			REP(y,4) REP(x,4)
				if (f[y][x] == '.')
					fo = true;
			if (fo)
				printf("Game has not completed\n");
			else
				printf("Draw\n");
		}
	}
	return 0;
}
