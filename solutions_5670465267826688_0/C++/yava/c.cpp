#include <stdio.h>

int l, n;
long long x;
char s[10240 * 16];
char a[10240 * 16];

char Mul(char x, char y) {
	int sign = 1;
	if (x < 0) {
		x = -x;
		sign = -sign;
	}
	if (y < 0) {
		y = -y;
		sign = -sign;
	}
	if (x == 1) { return y * sign; }
	if (y == 1) { return x * sign; }
	if (x == y) { return -sign; }
	if (x == 2 && y == 3) { return  sign * 4; }
	if (x == 2 && y == 4) { return -sign * 3; }
	if (x == 3 && y == 2) { return -sign * 4; }
	if (x == 3 && y == 4) { return  sign * 2; }
	if (x == 4 && y == 2) { return  sign * 3; }
	if (x == 4 && y == 3) { return -sign * 2; }
	return 1;
}

bool Find() {
	if (a[n-1] != -1) {
		return false;
	}
	int f = 0;
	for (int i=0; i<n; i++) {
		if (f == 0 && a[i] == 2) {
			f++;
		} else if (f == 1 && a[i] == 4) {
			f++;
			break;
		}
	}
	return f == 2;
}

void Solve() {
	scanf("%d %lld", &l, &x);
	scanf("%s", s);

	if (x > 12) {
		x = (x-12) % 4 + 12;
	}
	n = l * x;
	for (int i=l; i<n; i++) {
		s[i] = s[i%l];
	}
	s[n] = 0;
	for (int i=0; i<n; i++) {
		a[i] = (s[i] == 'i' ? 2 : (s[i] == 'j' ? 3 : 4));
	}
	for (int i=1; i<n; i++) {
		a[i] = Mul(a[i-1], a[i]);
	}
	bool ans = Find();
	printf("%s\n", ans ? "YES" : "NO");
}

int main() {
	int t = 0;
	scanf("%d", &t);
	for (int i=1; i<=t; i++) {
		printf("Case #%d: ", i);
		Solve();
	}
	return 0;
}
