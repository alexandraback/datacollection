#include<cstdio>

int t, d, e, p[1005], ans, sp;

int min(int x, int y) {
	return x < y ? x : y;
}

int main() {
//	freopen("B-large.in", "r", stdin);
//	freopen("B-large.out", "w", stdout);
	scanf("%d", &t);
	for (int zzz = 1 ; zzz <= t ; zzz++) {
		ans = 1000;
		for (int i = 0 ; i < 1005 ; i++) p[i] = 0;
		scanf("%d", &d);
		for (int i = 0 ; i < d ; i++) {
			scanf("%d", &e);
			p[e]++;
		}
		for (int i = 1 ; i < 1000 ; i++) {
			sp = 0;
			for (int j = i + 1 ; j <= 1000 ; j++) {
				if (j % i == 0) sp += p[j] * (j / i - 1);
				else sp += p[j] * (j / i);
			}
			ans = min(ans, sp + i);
		}
		printf("Case #%d: %d\n", zzz, ans);
	}
	scanf("\n");
	return 0;
}
