#include <cstdio>
#include <cstring>
long long int t, p, q, akt, ret;
char in [50];
int main () {
	scanf ("%lld", &t);
	for (int test = 0; test < t; test ++) {
		scanf ("%s", in);
		p = q = 0;
		for (akt = 0; in [akt] != '/'; akt ++) p = p*10 + (int) in [akt] - 48;
		akt ++;
		for (; akt < strlen (in); akt ++) q = q*10 + (int) in [akt] - 48;

		ret = 0;
		for (int i = 0; i < 40 && p != 0; i ++) {
			p *= 2;
			if (p >= q) {
				if (ret == 0) ret = i + 1;
				p -= q;
			}
		}
		if (p == 0) printf ("Case #%d: %d\n", test + 1, ret);
		else printf ("Case #%d: impossible\n", test+1);

	}

	return 0;
}
