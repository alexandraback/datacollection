#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE *f = fopen((argc > 1 ? argv[1] : "in.txt"), "r");
	FILE *g = fopen("out.txt", "w");
	char str[100];
	char *s;
	int t;
	fscanf(f, "%d\n", &t);
	for (int test = 0; test < t; test++) {
		unsigned long long p, q;
		fgets(str, 100, f);
		s = str;
		sscanf(s, "%lld", &p);
		while (s[0] != '/')
			s++;
		s++;
		sscanf(s, "%lld", &q);
		
		if (p > q) {
			fprintf(g, "Case #%d: impossible\n", test + 1);
			continue;
		}
		int power = 0;
		while ((q & 1) == 0) {
			power++;
			q >>= 1;
		}
		if ((p % q) != 0) {
			fprintf(g, "Case #%d: impossible\n", test + 1);
			continue;
		}
		p = p / q;
		q = 1;
		while ((p & 1) == 0) {
			power--;
			p >>= 1;
		}
		if (power > 40) {
			fprintf(g, "Case #%d: impossible\n", test + 1);
			continue;
		}
		while (power > 0) {
			power--;
			q <<= 1;
		}
		int n = 0;
		while (p < q) {
			n++;
			q >>= 1;
		}

		fprintf(g, "Case #%d: %d\n", test + 1, n);
	}
	fclose(f);
	fclose(g);
	return 0;
}

