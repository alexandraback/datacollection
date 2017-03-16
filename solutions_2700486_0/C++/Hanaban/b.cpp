#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXX 40
#define MAXY 40

double P[21][MAXX * 2 + 1][MAXY + 1];
int B[MAXX * 2 + 1][MAXY + 1];

void calc(int n, int x, int y, double p) {
	if (n > 4) return;
	
	if (y == 0 || y >= 0 && B[x - 1][y - 1] && B[x + 1][y - 1]) {
		B[x][y] = 1;
		//printf("%d, %d, %d - %f\n", n, x, y, p);
#if 0
		for (int xx = 0; xx <= MAXX * 2; ++xx) {
			for (int yy = 0; yy <= MAXY; ++yy) {
				P[n][xx][yy] += B[xx][yy];
			}
		}
#else
		P[n][x][y] += p;
#endif
		calc(n + 1, MAXX, MAXY, p);
		B[x][y] = 0;
	}
	else if (B[x - 1][y - 1] && B[x + 1][y - 1] == 0) {
		calc(n, x + 1, y - 1, p);
	}
	else if (B[x - 1][y - 1] == 0 && B[x + 1][y - 1]) {
		calc(n, x - 1, y - 1, p);
	}
	else if (y >= 2 && B[x][y - 2] && B[x - 1][y - 1] == 0 && B[x + 1][y - 1] == 0) {
		calc(n, x - 1, y - 1, p / 2.0f);
		calc(n, x + 1, y - 1, p / 2.0f);
	} else {
		calc(n, x, y - 2, p);
	}
}
				
int main()
{
	int t;
	cin >> t;
	
	memset(B, 0, sizeof(B) );
	memset(P, 0, sizeof(P) );
	calc(1, MAXX, MAXY, 1.0f);
	
	for (int c = 1; c <= t; ++c) {
		int n, x, y;
		cin >> n >> x >> y;
		if (x < -MAXX || x > MAXX || y < 0 || y > MAXY) printf("Case #%d: %.7f\n", c, 0.0f);
		//else printf("Case #%d: %f\n", c, (double) P[n][MAXX + x][y] / P[n][MAXX][0]);
		else {
			double z = 0;
			for (int i = 1; i <= n; ++i) z += P[i][MAXX + x][y];
			printf("Case #%d: %.7f\n", c, z);
		}
	}
	
	return 0;
}
