#include<cstdio>

int n;
char c[2000];
int main() {
	int t;
	scanf("%d", &t);
	for (int ii = 1;ii <= t;ii++) {
		scanf("%d%s", &n, &c);
		int ret = 0;
		int res = 0;
		for (int i = 0;i <= n;i++) {
			int d = c[i] - '0';
			if (d == 0) {
				continue;
			}
			if (res < i) {
				ret += i - res;
				res = i + d;
			} else {
				res += d;
			}
		}
		printf("Case #%d: %d\n", ii, ret);
	}
	return 0;
}