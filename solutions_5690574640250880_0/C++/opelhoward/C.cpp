#include <cstdio>
#include <string>
#include <queue>
#include <set>
using namespace std;
int main() {
	int nt;
	scanf("%d", &nt);
	for (int t = 1; t <= nt; t++) {
		int r, c, m;
		scanf("%d %d %d", &r, &c, &m);
		char map[r][c];
		memset(map, '.', r*c);

		if ((r == 1) or (c == 1)) {
			if (r == 1)
				for (int j = 0; (j < c-1) and (m > 0); j++) {
					m--;
					map[0][j] = '*';
				}
			if (c == 1)
				for (int i = 0; (i < r-1) and (m > 0); i++) {
					m--;
					map[i][0] = '*';
				}
		}
		else if ((r*c-m != 7) and (r*c-m != 5)) {
			int i_min = 0, j_min = 0;
			while (r-i_min != c-j_min) {
				if (r-i_min > c-j_min) {
					for (int j = 0; (j < c-2) and (m > 0); j++) {
						m--;
						map[i_min][j] = '*';
					}
					if (m >= 2) {
						map[i_min][c-2] = '*';
						map[i_min][c-1] = '*';
						m -= 2;
					}
					i_min++;
				}
				if (r-i_min < c-j_min) {
					for (int i = 0; (i < r-2) and (m > 0); i++) {
						m--;
						map[i][j_min] = '*';
					}
					if (m >=2) {
						map[r-2][j_min] = '*';
						map[r-1][j_min] = '*';
						m -= 2;
					}
					j_min++;
				}
			}
			bool i_bool = true, j_bool = true;
			int i = i_min, j = j_min;
			for (; (i_bool or j_bool) and ((m > 0) and (m > (r-i_min-2)*(c-j_min-2)));) {
				if ((i < r-2) and ((m > 0) and (m > (r-i_min-2)*(c-j_min-2)))) {
					map[i][c-2] = '*';
					map[i][c-1] = '*';
					m -= 2;
					i++;
				}
				else
					i_bool = false;
				if  ((j < c-2) and ((m > 0) and (m > (r-i_min-2)*(c-j_min-2)))) {
					map[r-2][j] = '*';
					map[r-1][j] = '*';
					m -= 2;
					j++;
				}
				else
					j_bool = false;
			}
			if (m > 0) {
				for (int i = i_min; (i < r - 2) and (m > 0); i++)
					for (int j = j_min; (j < c - 2) and (m > 0); j++) {
						m--;
						map[i][j] = '*';
					}
			}
			if (m == 3) {
				for (int i = r-2; (i < r) and (m > 0); i++)
					for (int j = c-2; (j < c) and (m > 0); j++) {
						m--;
						map[i][j] = '*';
					}
			}
		}
		if (m == 0) {
			map[r-1][c-1] = 'c';
		}
		printf("Case #%d:\n", t);
		if (!m)
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++)
					printf("%c", map[i][j]);
				printf("\n");
			}
		else
			printf("Impossible\n");
	}
	return 0;
}