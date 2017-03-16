#include <bits/stdc++.h>

const int maxn = 233;

char a[maxn], b[maxn];
char c[maxn], d[maxn];
struct Limit {
	int l, r;
}lim[maxn];

long long ans;
long long ten[maxn];

int n;

void dfs(int dep, long long tot) {
	long long L = tot, R = tot;
	for (int i = dep; i <= n; ++i) {
		L += ten[i] * lim[i].l;
		R += ten[i] * lim[i].r;
	}
//printf("%s %s %d %lld %lld %lld ??? %lld\n", a + 1, b + 1, dep, tot, L, R, ans);
	if (ans <= L || -ans >= R) return ;
	if (dep > n) {
		if (ans > std::abs(tot)) {
			ans = std::abs(tot);
			strcpy(c, a + 1);
			strcpy(d, b + 1);
		}
		return ;
	}
	if (a[dep] == '?') {
		if (b[dep] == '?') {
			a[dep] = '0';
			for (int i = 0; i <= 9; ++i) {
				b[dep] = i + '0';
				dfs(dep + 1, tot - ten[dep] * i);
			}
			b[dep] = '0';
			for (int i = 0; i <= 9; ++i) {
				a[dep] = i + '0';
				dfs(dep + 1, tot + ten[dep] * i);
			}
			a[dep] = b[dep] = '?';
		}
		else {
			for (int i = 0; i <= 9; ++i) {
				a[dep] = i + '0';
				dfs(dep + 1, tot + ten[dep] * (i + '0' - b[dep]));
			}
			a[dep] = '?';
		}
	}
	else {
		if (b[dep] == '?') {
			for (int i = 0; i <= 9; ++i) {
				b[dep] = i + '0';
				dfs(dep + 1, tot + ten[dep] * (a[dep] - i - '0'));
			}
			b[dep] = '?';
		}
		else dfs(dep + 1, tot + ten[dep] * (a[dep] - b[dep]));
	}
	return ;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int Cases = 1; Cases <= T; ++Cases) {
		scanf("%s%s", a + 1, b + 1);
		n = strlen(a + 1);
		ten[n] = 1;
		for (int i = n - 1; i > 0; --i)
			ten[i] = 10LL * ten[i + 1];
		for (int i = 1; i <= n; ++i) {
			Limit u, v;
			if (a[i] == '?') u.l = 0, u.r = 9;
			else u.l = u.r = a[i] - '0';
			if (b[i] == '?') v.l = 0, v.r = 9;
			else v.l = v.r = b[i] - '0';
			lim[i].l = u.l - v.r;
			lim[i].r = u.r - v.l;
		}
		ans = 0;
		for (int i = 1; i <= n; ++i)
			ans += 9LL * ten[i];
		dfs(1, 0);
		printf("Case #%d: %s %s\n", Cases, c, d);
	}
	return 0;
}
