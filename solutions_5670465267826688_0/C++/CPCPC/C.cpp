#include <cstring>
#include <cstdio>
#define abs(x) (((x) > 0)? (x): -(x))
const int L = 10005;
const int c[5][5] = { {},
	{ 0, 1, 2, 3, 4 },
	{ 0, 2, -1, 4, -3 },
	{ 0, 3, -4, -1, 2 },
	{ 0, 4, 3, -2, -1 }};
int calc(int a, int b) {
	int ans = (a*b < 0)? -1: 1;
	a = abs(a); b = abs(b);
	return ans*c[a][b];
}
char s[L];
long long T, n, m, a[L];
bool calc(long long n, long long m, char* s) {
	int ans = 1;
	for (int i = 0; i < n; i++) {
		switch (s[i]) {
			case 'i': a[i] = 2; break;
			case 'j': a[i] = 3; break;
			case 'k': a[i] = 4; break;
		}
		ans = calc(ans, a[i]);
	}
	int t = ans;
	for (int k = 1; k < m%4; k++) ans = calc(ans, t);
	if ((m%4 == 0)||(ans != -1)) return false;
	ans = 1;
	bool ok = false;
	int l, r;
	for (int k = 0; (k < 4)&&(k < m)&&(!ok); k++)
		for (int i = 0; i < n; i++) {
			ans = calc(ans, a[i]);
			if (ans == 2) {
				ok = true;
				l = k*n+i+1;
				break;
			}
		}
	if (!ok) return false;
	ans = 1;
	ok = false;
	for (int k = 0; (k < 4)&&(k < m)&&(!ok); k++)
		for (int i = n-1; i >= 0; i--) {
			ans = calc(a[i], ans);
			if (ans == 4) {
				ok = true;
				r = k*n+n-i;
				break;
			}
		}
	if (!ok) return false;
	if (l+r >= n*m) return false;
	return true;
}
int main() {
	scanf("%lld", &T);
	for (int C = 1; C <= T; C++) {
		scanf("%lld%lld%s", &n, &m, s);
		printf("Case #%d: %s\n", C, calc(n, m, s)? "YES": "NO");
	}
	return 0;
}
