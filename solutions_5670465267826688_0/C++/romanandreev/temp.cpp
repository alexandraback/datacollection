#include <bits/stdc++.h>
using namespace std;
struct quat {
	int sgn;
	int tp;
	quat(char c) {
		sgn = 1;
		if (c == 'i') {
			tp = 1;
		}
		if (c == 'j') {
			tp = 2;
		}
		if (c == 'k') {
			tp = 3;
		}
	}
	quat(int s, int t):sgn(s),tp(t) {
	}
	quat() {
	}
};
quat mul(quat a, quat b) {
	if (a.tp == 0 || b.tp == 0) {
		return quat(a.sgn * b.sgn, a.tp + b.tp);
	}
	if (a.tp == b.tp) {
		return quat(-a.sgn * b.sgn, 0);
	}
	int s = 1;
	if ((a.tp + 2 - 1) % 3 + 1 == b.tp) {
		s = -1;
	}
	return quat(a.sgn * b.sgn * s, 6 - a.tp - b.tp);
}
quat inv(quat a) {
	quat res = a;
	if (a.tp > 0) {
		res.sgn *= -1;
	}
	return res;
}
bool operator == (quat a, quat b) {
	return a.sgn == b.sgn && a.tp == b.tp;
}
int n, x;
char s[100000];
quat a[100000];
quat sum[100000];

void solve() {
	scanf("%d %d", &n, &x);
	scanf("%s", s);	
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < n; j++) {
			a[i * n + j] = quat(s[j]);
		}
	}
	n *= x;
	sum[0] = quat(1, 0);
	for (int i = 0; i < n; i++) {
		sum[i + 1] = mul(sum[i], a[i]);
	}
	if (!(sum[n] == mul(quat('i'), mul(quat('j'), quat('k'))))) {
		printf("NO\n");
		return;
	}
	int ps1 = -1;
	for (int i = 0; i <= n; i++) {
		if (sum[i] == quat('i')) {
			ps1 = i;
			break;
		}
	}
	int ps2 = -1;
	for (int i = n; i >= 0; i--) {
		if (sum[i] == mul(quat('i'), quat('j'))) {
			ps2 = i;
			break;
		}
	}
	if (ps1 != -1 && ps2 != -1 && ps1 < ps2) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}
int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++) {
		printf("Case #%d: ", ti);
		solve();
	}
	return 0;
}