#include <stdio.h>
#include <string.h>

int n, x, a[305], b[19];
char t[2016];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);

	int c;

	for (int i = 1; i <= n; i++) {
		scanf("%s", t + 1);
		x = strlen(t + 1);

		for (int j = 1; j <= 300; j++) {
			a[j] = 0;
		}
		for (int j = 0; j <= 9; j++) {
			b[j] = 0;
		}

		for (int j = 1; j <= x; j++) {
			a[t[j]]++;
		}

		// 6
		if (a['X'] > 0) {
			c = a['X'];
			b[6] += c;
			a['S'] -= c;
			a['I'] -= c;
			a['X'] -= c;
		}

		// 0
		if (a['Z'] > 0) {
			c = a['Z'];
			b[0] += c;
			a['Z'] -= c;
			a['E'] -= c;
			a['R'] -= c;
			a['O'] -= c;
		}

		// 8
		if (a['G'] > 0) {
			c = a['G'];
			b[8] += c;
			a['E'] -= c;
			a['I'] -= c;
			a['G'] -= c;
			a['H'] -= c;
			a['T'] -= c;
		}

		// 4
		if (a['U'] > 0) {
			c = a['U'];
			b[4] += c;
			a['F'] -= c;
			a['O'] -= c;
			a['U'] -= c;
			a['R'] -= c;
		}

		// 5
		if (a['F'] > 0) {
			c = a['F'];
			b[5] += c;
			a['F'] -= c;
			a['I'] -= c;
			a['V'] -= c;
			a['E'] -= c;
		}

		// 7
		if (a['V'] > 0) {
			c = a['V'];
			b[7] += c;
			a['S'] -= c;
			a['E'] -= c;
			a['V'] -= c;
			a['E'] -= c;
			a['N'] -= c;
		}

		// 3
		if (a['R'] > 0) {
			c = a['R'];
			b[3] += c;
			a['T'] -= c;
			a['H'] -= c;
			a['R'] -= c;
			a['E'] -= c;
			a['E'] -= c;
		}

		// 2
		if (a['W'] > 0) {
			c = a['W'];
			b[2] += c;
			a['T'] -= c;
			a['W'] -= c;
			a['O'] -= c;
		}

		// 1
		if (a['O'] > 0) {
			c = a['O'];
			b[1] += c;
			a['O'] -= c;
			a['N'] -= c;
			a['E'] -= c;
		}

		// 9
		if (a['I'] > 0) {
			c = a['I'];
			b[9] += c;
			a['N'] -= c;
			a['I'] -= c;
			a['N'] -= c;
			a['E'] -= c;
		}

		printf("Case #%d: ", i);

		for (int j = 0; j <= 9; j++) {
			for (int k = 1; k <= b[j]; k++) {
				printf("%d", j);
			}
		}
		printf("\n");
	}

	return 0;
}