#include <cstdio>
bool calc(int x, int r, int c) {
	if (r*c%x != 0) return false;
	if ((x > r)&&(x > c)) return false;
	if ((x > 2*r)||(x > 2*c)) return false;
	if (x >= r+c-1) return false;
	if (x > 6) return false;
	return true;
}
int main() {
	int T, x, r, c;
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		scanf("%d%d%d", &x, &r, &c);
		printf("Case #%d: %s\n", C, calc(x, r, c)? "GABRIEL": "RICHARD");
	}
	return 0;
}
