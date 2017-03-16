#include <stdio.h>

int main (void) {
	int T, c;
	long long r, t, i, ans;
	scanf ("%d", &T);
	for (c = 1; c <= T; c++) {
		printf ("Case #%d: ", c);
		scanf ("%Ld%Ld", &r, &t);
		ans = 0;
		while (t >= 2*r+1) {
			t -= 2*r+1;
			r+=2;
			ans++;
		}
		printf ("%Ld\n", ans);
	}
	return 0;
}
