#include <cstdio>

int Main () {
	int k, c, s;
	scanf ("%d %d %d", &k, &c, &s);
	
	for (int i=0; i<k; i++) printf (" %d", i + 1);
	printf ("\n");
	
	return 0;
}

int main () {

	freopen ("D-small-attempt0.in", "r", stdin);
	freopen ("D-small-attempt0.out", "w", stdout);

	int t;
	scanf ("%d", &t);
	
	for (int tc=0; tc<t; tc++) {
		printf ("Case #%d:", tc + 1);
		Main ();
	}
	return 0;
}