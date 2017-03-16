#include <stdio.h>

int main () {
	freopen ("B-large.in" , "r" , stdin);
	freopen ("output.txt" , "w" , stdout);
	int tt, t, n, s, p, sc, k, ans;
	scanf ("%d" , &tt);
	for (t = 1 ; t <= tt ; t++) {
		scanf ("%d%d%d" , &n , &s , &p);
		ans = 0;
		while (n--) {
			scanf ("%d" , &sc);
			k = sc / 3;
			switch (sc % 3) {
			case 0 :
				if (k >= p) {
					ans++;
				}
				else if (s > 0 && k + 1 >= p && k + 1 <= 10 && k - 1 >= 0) {
					s--;
					ans++;
				}
				break;
			case 1 :
				if (k + 1 >= p) {
					ans++;
				}
				break;
			case 2 :
				if (k + 1 >= p) {
					ans++;
				}
				else if (s > 0 && k + 2 >= p && k + 2 <= 10) {
					s--;
					ans++;
				}
				break;
			}
		}
		printf ("Case #%d: %d\n" , t , ans);
	}
}