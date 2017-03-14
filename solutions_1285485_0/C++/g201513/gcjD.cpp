#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

using namespace std;

const double eps = 1e-7;

int n, m, k, sx, sy;
char s[35][35];
bool u[105][105];

int gcd(int a, int b) {
	if(b==0) return a;
	else return gcd(b, a%b);
}

double get(double x, double d) {
	if(d > eps) {
		double res = (int)(x+1) - x;
		while(res > 1) res -= 1;
		while(res < eps) res += 1;
		return res / d;
	} else if(d < -eps) {
		double res = x - (int)x;
		while(res > 1) res -= 1;
		while(res < eps) res += 1;
		return res / -d;
	} else {
		return 1.0;
	}
}

double SX, SY;

bool go(double sx, double sy, double dx, double dy) {
	double t = min(1.0, min(get(sx, dx), get(sy, dy)));

	sx += dx * t;
	sy += dy * t;
	dx -= dx * t;
	dy -= dy * t;

	if(fabs(t-1) < eps) {
		return fabs(sx - SX) < eps && fabs(sy - SY) < eps;
	}

	int x, y, block=0;

	if(fabs(sx - (int)(sx+.5)) < eps) block |= 1;
	if(fabs(sy - (int)(sy+.5)) < eps) block |= 2;

	if(dx > 0) x = (int)(sx + eps);
	else x = (int)(sx - eps);
	if(dy > 0) y = (int)(sy + eps);
	else y = (int)(sy - eps);

	if(s[x][y] != '#') return go(sx, sy, dx, dy);

	if(block == 1) return go(sx, sy, -dx, dy);
	else if(block == 2) return go(sx, sy, dx, -dy);
	else {
		int DX = dx > 0 ? -1 : 1;
		int DY = dy > 0 ? -1 : 1;

		bool px = (s[x+DX][y] == '#');
		bool py = (s[x][y+DY] == '#');

		if(px && py) {
			return go(sx, sy, -dx, -dy);
		} else if(px) {
			return go(sx, sy, dx, -dy);
		} else if(py) {
			return go(sx, sy, -dx, dy);
		} else {
			return false;
		}
	}
}

bool check(int dx, int dy) {
	SX = sx+0.5; SY = sy+0.5;
	return go(SX, SY, dx, dy);
}

int main() {
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);

	int ntest;
	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		scanf("%d%d%d", &n, &m, &k);
		for(int i=0; i<n; i++) {
			scanf("%s", s[i]);
			for(int j=0; j<m; j++) {
				if(s[i][j] == 'X') {
					sx = i;
					sy = j;
				}
			}
		}

		memset(u, 0, sizeof(u));
		for(int dx = -k; dx <= k; dx++) for(int dy = -k; dy <= k; dy++) {
			if(dx*dx+dy*dy == 0 || dx*dx+dy*dy > k*k) continue;
			if(check(dx, dy)) {
		//		printf("%d %d\n", dx, dy);
				int p = gcd(abs(dx), abs(dy));
				u[(dx/p)+50][(dy/p)+50] = true;
			}
		}

		int ans = 0;
		for(int dx = -k; dx <= k; dx++) for(int dy = -k; dy <= k; dy++) {
			if(u[dx+50][dy+50]) {
		//		printf("!%d %d\n", dx, dy);
				ans++;
			}
		}

		printf("Case #%d: %d\n", test, ans);
	}

	return 0;
}