#include <cstdio>

int t, r, c, m; char tr[55][55][2567], ism[55][55];
// tr: 0 is down, 1 is left
int main() {
	freopen("c.in", "r", stdin); freopen("c.out", "w", stdout);
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		printf("Case #%d:\n", tc);
		scanf("%d %d %d", &r, &c, &m);
		if (r==1) {
			for (int i = 0; i < m; i++) putchar('*');
			for (int i = m; i < c-1; i++) putchar('.');
			puts("c"); continue;
		}
		if (c==1) {
			for (int i = 0; i < m; i++) puts("*");
			for (int i = m; i < r-1; i++) puts(".");
			puts("c"); continue;
		}
		if (m==r*c-1) {
			putchar('c');
			for (int x = 1; x < c; x++) putchar('*');
			putchar('\n');
			for (int y = 1; y < r; y++) {
				for (int x = 0; x < c; x++) putchar('*');
				putchar('\n');
			}
			continue;
		}
		if (m==r*c-2 || m==r*c-3 || (c==2 && m%2)) {
			puts("Impossible"); continue;
		}
		if (c==2) {
			for (int y = 0; y < r-1; y++) puts(2*y+2 <= m ? "**" : "..");
			puts(".c"); continue;
		}
		for (int y = 0; y <= r; y++) for (int x = 0; x <= c; x++) {
			ism[y][x] = 0;
			for (int mn = 0; mn <= r*c; mn++) tr[x][y][mn] = -1;
		}
		for (int y = r; y > 1; y--) tr[2][y][3*(r-y)] = 1;
		for (int x = 2; x < c; x++) for (int y = r; y >= 0; y--) for (int mn = 0; mn <= m; mn++) if (tr[x][y][mn] != -1) {
			//printf("%d %d %d\n", x, y, mn);
			if (y && mn < m) tr[x][y-1][mn+1] = 0;
			if (x < c-1 && y!=1 && mn+(r-y) <= m) tr[x+1][y][mn+r-y] = 1;
		}
		int tx = c-1, ty = -1, tm = m;
		for (int y = 0; y <= r; y++) if (y != 1 && tr[c-1][y][m]!=-1) ty = y;
		//printf("%d\n", ty);
		if (ty==-1) {
			puts("Impossible"); continue;
		}
		while (tx > 1) {
			for (int y = ty; y < r; y++) ism[y][tx] = 1;
			if (tr[tx][ty][tm]==0) {
				ty++; tm--;
			}
			else {
				tx--; tm -= r-ty;
			}
		}
		for (int y = ty; y < r; y++) ism[y][0] = ism[y][1] = 1;
		for (int y = 0; y < r; y++) {
			for (int x = 0; x < c; x++) putchar(!x && !y ? 'c' : ism[y][x] ? '*' : '.');
			putchar('\n');
		}
	}

	return 0;
}