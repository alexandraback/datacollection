#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, k, t, pts, tm, N, cmax, tt, yy;
	char buf[1024];
	char *buf2;
	int nbuf[1000][4];
	int state[1000];
	int ah[1000][3];
	int m;
	int nlen;
	while (getchar() != '\n');
	while (fgets(buf, 1024, stdin)) {
		sscanf(buf, "%d", &N);
		for (i = 0; i < N; i++) {
			fgets(buf, 1024, stdin);
			buf2 = buf;
			for (nlen = 0; *buf2 != '\0' && nlen < 512; nlen++) {
				while (*buf2 == ' ' || *buf2 == '\t'
						    || *buf2 == '\n') buf2++;
				nbuf[i][nlen] = atoi(buf2);
				while (*buf2 != ' ' && *buf2 != '\t' && *buf2 != '\n'
						    && *buf2 != '\0') buf2++;
			}
			state[i] = 0;
		}
		pts = 0;
		tm = 0;
		while (1) {
			m = 0;
			cmax = -1;
			for (i = 0; i < N; i++) {
				if (state[i] == 0) {
					if (nbuf[i][0] >= cmax && nbuf[i][0] <= pts) {
						cmax = nbuf[i][0];
						ah[m][0] = nbuf[i][0];
						ah[m][1] = i;
						ah[m++][2] = 1;
					}
					if (nbuf[i][1] >= cmax && nbuf[i][1] <= pts) {
						cmax = nbuf[i][1];
						k = i;
						t = 2;
					}
				} else if (state[i] == 1) {
					if (nbuf[i][1] > cmax && nbuf[i][1] <= pts) {
						cmax = nbuf[i][1];
						k = i;
						t = 1;
					} else if (nbuf[i][1] == cmax && nbuf[i][1] <= pts && state[k] != 1) {
						cmax = nbuf[i][1];
						k = i;
						t = 1;
					}
				}
			}
			for (i = 0; i < m; i++)
				if (ah[i][0] < cmax) goto asd;
			for (i = 0; i < m; i++) {
				tt = nbuf[ah[i][1]][1];
				if (tt > nbuf[k][1]) {
					k = ah[i][1];
					t = ah[i][2];
				}
			}
asd:
			if (cmax == -1) {
				for (i = 0; i < N; i++)
					if (state[i] != 2) goto fail;
				break;
			}
			tm++;
			pts += t;
			state[k] += t;
		}
		printf("%d\n", tm);
		continue;
fail:
		printf("Too Bad\n");
	}
}
