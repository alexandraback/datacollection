#include <stdio.h>
#include <string.h>

#define MAXN 4001

double c[MAXN][MAXN];
double pow[MAXN];

int cal(int level) {
	if(level == 0) return 0;
	int first = 1;
	int last = first + (level - 1) * 4;
	return (first + last) * level / 2;
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("out.out", "w", stdout);
//	for(int i = 1; i <= 4000; ++i) c[i][0] = c[i][i] = 1.0;
//	for(int i = 2; i <= 4000; ++i)
//		for(int j = 1; j < i; ++j) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
//	pow[0] = 1.0;
//	for(int i = 1; i <= 4000; ++i) pow[i] = pow[i - 1] * 0.5;
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas) {
		int n, x, y;
		scanf("%d%d%d", &n, &x, &y);
		if(x < 0) x = -x;
		int level = (x + y) / 2 + 1;
		int low = cal(level - 1);
		int high = cal(level);
//		printf("%d %d\n", low, high);
		double res = 0.0;
		if(n >= high)
			res = 1.0;
		else if(n <= low)
			res = 0.0;
		else {
			int sum = high - low;
			int rem = n - low;
			int pos = y + 1;
			if(pos * 2 - 1 == sum) res = 0.0;
			else {
				int half = sum / 2;
				for(int i = 0; i <= 1100; ++i)
					for(int j = 0; j <= 1100; ++j) c[i][j] = 0.0;
//				printf("%d %d\n", half, rem);
				c[0][0] = 1.0;
				for(int i = 0; i <= half && i < rem; ++i)
					for(int j = 0; j <= half && i + j < half * 2 && i + j < rem; ++j) {
						double p1, p2;
						if(i == half) {
							p1 = 0.0;
							p2 = 1.0;
						} else if(j == half) {
							p1 = 1.0;
							p2 = 0.0;
						} else {
							p1 = p2 = 0.5;
						}
						if(i != half) c[i + 1][j] += c[i][j] * p1;
						if(j != half) c[i][j + 1] += c[i][j] * p2;
					}
//				printf("%.3f %.3f %.3f %.3f %.3f\n", c[0][1], c[1][0], c[1][1], c[2][0], c[0][2]);
				res = 0.0;
				for(int i = pos; i <= rem && i <= half; ++i)
					res += c[rem - i][i];
			}
		}
		printf("Case #%d: %.9f\n", cas, res);
	}
	return 0;
}
