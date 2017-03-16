#include <stdio.h>
#include <string.h>

int ti, tn, i, j, n, best, used[1005], bff[1005], rela[1000][1000];

void
calc(int head, int cur, int sat, int dir, int len) {
	int i;

	if (len > best) {
		if (sat) {
			best = len;
		}
	}
	if (!used[bff[cur]]) {
		used[bff[cur]] = 1;
		calc(head, bff[cur], (bff[bff[cur]] == cur) | ((bff[bff[cur]] == head) << 1), 1, len + 1);
		used[bff[cur]] = 0;
	}
	if (sat & 1) {
		for (i = 1; i <= rela[cur][0]; ++i) {
			if (!used[rela[cur][i]]) {
				used[rela[cur][i]] = 1;
				calc(head, rela[cur][i], 1, 0, len + 1);
				used[rela[cur][i]] = 0;
			}
		}
	}
}

int
main() {
	fscanf(stdin, "%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		fprintf(stdout, "Case #%d: ", ti);
		fscanf(stdin, "%d", &n);
		for (i = 0; i < n; ++i) {
			rela[i][0] = 0;
			used[i] = 0;
		}
		for (i = 0; i < n; ++i) {
			scanf("%d", &bff[i]);
			--bff[i];
			rela[bff[i]][++rela[bff[i]][0]] = i;
		}
		for (i = 0, best = 1; i < n; ++i) {
			used[i] = 1;
			calc(i, i, 0, 1, 1);
			used[i] = 0;
		}
		fprintf(stdout, "%d\n", best);
	}
}

