#include <iostream>
#include <cstdio>
using namespace std;

long long dp[20][10][10][2];
bool et[20][10][10][2];
int pre[20][10][10][2][3];
char a[20], b[20];

void output(int dig) {
	long long v = 0;
	bool e = 1;
	int x, y, z;
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			if (!et[0][i][j][0]) {
				if (e || abs(v) > abs(dp[0][i][j][0])) {
					e = 0;
					v = dp[0][i][j][0];
					x = i;
					y = j;
					z = 0;
				}
			}
		}
	}
	int idx = 0;
	while(idx < dig) {
		a[idx] = x + '0';
		b[idx] = y + '0';
		int * p = pre[idx][x][y][z];
		x = p[0];
		y = p[1];
		z = p[2];
		idx ++;
	}
}

void B() {
	freopen("b.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int cas = 1;cas <= t;cas++) {
		scanf(" %s %s", a, b);
		memset(et, 1, sizeof et);
		memset(pre, -1, sizeof pre);
		int ln = strlen(a);
		for (int i = 0;i < 10;i++) {
			for (int j = 0;j < 10;j++) {
				dp[ln][i][j][0] = 0;
				dp[ln][i][j][1] = 0;
				et[ln][i][j][0] = 0;
				et[ln][i][j][1] = 0;
			}
		}
		long long ten = 1;
		for (int i = ln - 1;i >= 0;i--) {
			int si = 0, ei = 9, sj = 0, ej = 9;
			if (a[i] != '?')
				si = ei = a[i] - '0';
			if (b[i] != '?')
				sj = ej = b[i] - '0';
			for (int ii = si;ii <= ei;ii++) {
				for (int jj = sj;jj <= ej;jj++) {
					long long dist = (ii - jj) * ten;
					//for (int h = 0;h < 2;h++) {
						int * pos = pre[i][ii][jj][0];
						for (int di = 0;di < 10;di++) {
							for (int dj = 0;dj < 10;dj++) {
								for (int l = 0;l < 2;l++) {
									if (!et[i + 1][di][dj][l]) {
										long long v = dist + dp[i + 1][di][dj][l];
										if (et[i][ii][jj][0] || abs(dp[i][ii][jj][0]) > abs(v)) {
											et[i][ii][jj][0] = 0;
											dp[i][ii][jj][0] = v;
											pos[0] = di;
											pos[1] = dj;
											pos[2] = l;
										}
									}
								}
							}
						}
					//}
						pos = pre[i][ii][jj][1];
						for (int di = 0;di < 10;di++) {
							for (int dj = 0;dj < 10;dj++) {
								for (int l = 0;l < 2;l++) {
									if (!et[i + 1][di][dj][l]) {
										long long v = dist + dp[i + 1][di][dj][l];
										if (et[i][ii][jj][1] || abs(dp[i][ii][jj][1]) < abs(v)) {
											et[i][ii][jj][1] = 0;
											dp[i][ii][jj][1] = v;
											pos[0] = di;
											pos[1] = dj;
											pos[2] = l;
										}
									}
								}
							}
						}
				}
			}
			ten *= 10;
		}
		output(ln);
		printf("Case #%d: %s %s\n", cas, a, b);
	}
}

int main() {
	B();
}