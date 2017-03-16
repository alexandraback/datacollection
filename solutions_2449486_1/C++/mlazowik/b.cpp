// Michal Lazowik
//
// Google Code Jam 2013
// Qualification Round
// Problem B. Lawnmower

#include <cstdio>

using namespace std;

#define REP(x, n) for (int x = 0; x < n; ++x)

const int MAX = 110;

int n, m, target[MAX][MAX];

bool isRowFree(int x, int h) {
	REP(y, m)
		if (target[x][y] > h)
			return false;

	return true;
}

bool isColFree(int y, int h) {
	REP(x, n)
		if (target[x][y] > h)
			return false;
	return true;
}

bool justDoIt() {
	REP(x, n) REP(y, m)
		if (!isRowFree(x, target[x][y]) && !isColFree(y, target[x][y]))
			return false;

	return true;
}

int main() {
	int t;

	scanf("%d", &t);
	REP(q, t) {
		scanf("%d %d", &n, &m);
		REP(x, n) REP(y, m)
			scanf("%d", &target[x][y]);

		printf("Case #%d: ", q+1);
		(justDoIt()) ? printf("YES\n") : printf("NO\n");
	}

	return 0;
}
