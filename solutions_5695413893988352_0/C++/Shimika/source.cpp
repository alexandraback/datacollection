#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, x, a[305], b[19];
char t1[20], t2[20];
char s1[20], s2[20];
char w1[20], w2[20];
int l1, l2;
int mx, c, j;

void recall(int type, int lev) {
	if (type == 1) {
		if (lev > l1) {
			recall(2, 1);
		}
		else {
			if (t1[lev] == '?') {
				for (int i = 0; i <= 9; i++) {
					s1[lev] = i + '0';
					recall(type, lev + 1);
				}
			}
			else {
				recall(type, lev + 1);
			}
		}
	}
	else {
		if (lev > l2) {
			int v1, v2;
			v1 = v2 = 0;
			for (int i = 1; i <= l1; i++) {
				v1 = v1 * 10 + (s1[i] - '0');
			}
			for (int i = 1; i <= l2; i++) {
				v2 = v2 * 10 + (s2[i] - '0');
			}

			//printf("%s %s: %d %d\n", s1 + 1, s2 + 1, v1, v2);

			if (abs(v1 - v2) < mx) {
				mx = abs(v1 - v2);
				c = v1;
				j = v2;

				strcpy(w1 + 1, s1 + 1);
				strcpy(w2 + 1, s2 + 1);
			}
			else if (abs(v1 - v2) == mx) {
				if (c > v1 || (c == v1 && j > v2)) {
					c = v1;
					j = v2;
					strcpy(w1 + 1, s1 + 1);
					strcpy(w2 + 1, s2 + 1);
				}
			}
		}
		else {
			if (t2[lev] == '?') {
				for (int i = 0; i <= 9; i++) {
					s2[lev] = i + '0';
					recall(type, lev + 1);
				}
			}
			else {
				recall(type, lev + 1);
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%s %s", t1 + 1, t2 + 1);
		l1 = strlen(t1 + 1);
		l2 = strlen(t2 + 1);

		mx = 1000000;


		strcpy(s1 + 1, t1 + 1);
		strcpy(s2 + 1, t2 + 1);

		recall(1, 1);

		printf("Case #%d: %s %s\n", i, w1 + 1, w2 + 1);
	}

	return 0;
}