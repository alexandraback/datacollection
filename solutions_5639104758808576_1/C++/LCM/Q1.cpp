#include<cstdio>

int t, m, tt, ans;
char c;

int main() {
//	freopen("A-large.in", "r", stdin);
//	freopen("A-large.out", "w", stdout);
	scanf("%d", &t);
	for (int zzz = 1 ; zzz <= t ; zzz++) {
		tt = 0;
		ans = 0;
		scanf("%d", &m);
		for (int i = 0 ; i <= m ; i++) {
			scanf("%c", &c);
			while (c > '9' || c < '0') scanf("%c", &c);
			if (tt < i) {
				int diff = i - tt;
				ans += diff;
				tt += diff;
			}
			tt += c - '0';
		}
		printf("Case #%d: %d\n", zzz, ans);
	}
	scanf("\n");
	return 0;
}
