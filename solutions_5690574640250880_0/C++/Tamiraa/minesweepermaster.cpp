#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
char board[51][51];
int cnt[51][51];
bool used[51][51];

char xx[] = {0, 1, 1, 1, 0, -1, -1, -1};
char yy[] = {1, 1, 0, -1, -1, -1, 0, 1};

bool ok(int x, int y, int r, int c) {
	return x>=0 && x<r && y>=0 && y < c;
}

int fnd(int x, int y, int r, int c) {
	int ret = 0;
	for (int i = 0; i < 8; i++) {
		int dx = x+xx[i];
		int dy = y+yy[i];
		if (ok(dx, dy, r, c) && board[dx][dy]=='*')
			ret++;
	}
	return ret;
}

void rec(int x, int y, int r, int c) {
	used[x][y] = 1;
	if (cnt[x][y] != 0)
		return;
	for (int i = 0; i < 8; i++) {
		int dx = x+xx[i];
		int dy = y+yy[i];
		if (ok(dx, dy, r, c) && !used[dx][dy] && board[dx][dy]!='*') 
			rec(dx, dy, r, c);
	}
}

int main() {
	freopen("C-small-attempt3.in", "r", stdin);
	//freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		printf("Case #%d:\n", tt);
		int r, c, m;
		scanf("%d%d%d", &r, &c, &m);
		int k = r*c;
		bool retFound = 0;

		for (int i = 0; i < (1<<k); i++) {
			if (__builtin_popcount(i) == m) {
				int kk = 0;
				int kx = 0, ky = 0;
				for (int j = 0; j < k; j++) {
					board[kx][ky] = ((1<<j)&i)!=0?'*':'.';
					ky++;
					if (ky == c) {
						ky = 0;
						kx++;
					}
				}
				memset(cnt, -1, sizeof cnt);
				memset(used, 0, sizeof used);
				int sx, sy;
				for (int x = 0; x < r; x++)
				for (int y = 0; y < c; y++)
					if (board[x][y] != '*') {
						cnt[x][y] = fnd(x, y, r, c);
						if (cnt[x][y] == 0) {
							sx = x; sy = y;
						}
					}
				rec(sx, sy, r, c);

				bool covered = 1;
				for (int x = 0; x < r; x++)
				for (int y = 0; y < c; y++)
					if (board[x][y]!='*' && !used[x][y]) {
						covered = 0;
						x = r;
						break;
					}
				if (covered) {
					board[sx][sy] = 'c';
					for (int x = 0; x < r; x++) {
						for (int y = 0; y < c; y++)
							printf("%c", board[x][y]);
						printf("\n");
					}
					retFound = 1;
					i = (1<<k);
					break;
				} else {
					if (k-m == 1) {
						for (int x = 0; x < r; x++) {
							for (int y = 0; y < c; y++)
								printf("%c", board[x][y]=='*'?'*':'c');
							printf("\n");
						}
						retFound = 1;
						i = (1<<k);
						break;
					}
				}
			}
		}
		if (!retFound)
				printf("Impossible\n");

	}
	return 0;
}