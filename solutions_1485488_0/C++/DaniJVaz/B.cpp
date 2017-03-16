#include <cstdio>
#include <queue>

using namespace std;

struct coord {
	coord(int i, int j, double t) : i(i), j(j), t(t) {}
	int i, j;
	double t;
};

bool operator < (const coord & a, const coord & b) {
	return a.t < b.t;
}

const int MAXN = 100, MAXM = 100;
int floor[MAXN][MAXM];
int ceil[MAXN][MAXM];
double localMin[MAXN][MAXM];

const double MIN_DIFF = 50;
const double VEL_DOWN = 10;
const double MIN_KAYAK = 20;

void transit(priority_queue<coord> & q, coord p, coord & p2, int n, int m, int h) {
	if (p2.i < 0 or p2.i >= n or p2.j < 0 or p2.j >= m)
		return;

	if (ceil[p2.i][p2.j] - floor[p.i][p.j] < MIN_DIFF)
		return;

	if (ceil[p2.i][p2.j] - floor[p2.i][p2.j] < MIN_DIFF)
		return;

	if (ceil[p.i][p.j] - floor[p2.i][p2.j] < MIN_DIFF)
		return;

	if (p.t == 0 and ceil[p2.i][p2.j] - h >= MIN_DIFF) {
		if (0 < localMin[p2.i][p2.j]) {
			localMin[p2.i][p2.j] = 0;
			q.push(coord(p2.i, p2.j, 0));
		}
	}
	else {
		if (ceil[p2.i][p2.j] - (h - VEL_DOWN*p.t) < MIN_DIFF)
			p.t = (h + MIN_DIFF - ceil[p2.i][p2.j]) / VEL_DOWN;

		//printf("%lf %d\n", )
		if ((h - VEL_DOWN*p.t) - floor[p.i][p.j] >= MIN_KAYAK) {
			if (p.t + 1 < localMin[p2.i][p2.j]) {
				localMin[p2.i][p2.j] = p.t + 1;
				q.push(coord(p2.i, p2.j, p.t + 1));
			}
		}
		else {
			if (p.t + 10 < localMin[p2.i][p2.j]) {
				localMin[p2.i][p2.j] = p.t + 10;
				q.push(coord(p2.i, p2.j, p.t + 10));
			}
		}
	}
}

int main() {
	int iC, nC;
	scanf("%d", &nC);
	for (iC = 1; iC <= nC; iC++) {
		int h, n, m;
		scanf("%d %d %d", &h, &n, &m);

		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				scanf("%d", &ceil[i][j]);

		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				scanf("%d", &floor[i][j]);

		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				localMin[i][j] = h*100;

		priority_queue<coord> q;
		q.push(coord(0,0,0));
		localMin[0][0] = 0;

		while (!q.empty()) {
			coord p = q.top(), p2(0,0,0);
			q.pop();

			p.t = localMin[p.i][p.j];
			//printf("temp: %d %d %lf\n", p.i, p.j, p.t);

			p2 = coord(p.i+1, p.j, 0);
			transit(q, p, p2, n, m, h);

			p2 = coord(p.i-1, p.j, 0);
			transit(q, p, p2, n, m, h);

			p2 = coord(p.i, p.j+1, 0);
			transit(q, p, p2, n, m, h);

			p2 = coord(p.i, p.j-1, 0);
			transit(q, p, p2, n, m, h);
		}

		printf("Case #%d: %.1lf\n", iC, localMin[n-1][m-1]);
	}
	return 0;
}
