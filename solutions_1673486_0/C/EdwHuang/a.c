#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a, b, i, j;
	double min_e, tmp, tmp2;
	char buf[1024];
	char *buf2;
	double nbuf[512];
	int nlen;
	while (getchar() != '\n');
	while (fgets(buf, 1024, stdin)) {
		sscanf(buf, "%d %d", &a, &b);
		fgets(buf, 1024, stdin);
		buf2 = buf;
		for (nlen = 0; *buf2 != '\0' && nlen < 512; nlen++) {
			while (*buf2 == ' ' || *buf2 == '\t'
					    || *buf2 == '\n') buf2++;
			nbuf[nlen] = atof(buf2);
			while (*buf2 != ' ' && *buf2 != '\t' && *buf2 != '\n'
					    && *buf2 != '\0') buf2++;
		}
		nlen--;
		min_e = b + 2;
		for (i = 0; i <= a; i++) {
			tmp = 1.0;
			for (j = 0; j < i; j++)
				tmp *= nbuf[j];
			tmp2 = tmp * (b-i+1.0) + (1.0-tmp) * (2.0*b-i+2);
			tmp2 += a - i;
			if (tmp2 <= min_e) min_e = tmp2;
			//printf("DBG %d %d %d %f %f %f\n", i, a, b, min_e, tmp, tmp2);
		}
		printf("%f\n", min_e);
	}
}
