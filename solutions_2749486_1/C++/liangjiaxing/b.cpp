#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
int a[3000];
string b = " NESW";

int main() {
	int T;
	freopen("B-large (4).in", "r", stdin);
	freopen("w.txt", "w", stdout); 
	scanf("%d", &T);
	for (int re = 1; re <= T; re++) {
		int X, Y;
		scanf("%d%d", &X, &Y);
		if (X < 0) {
			X = -X;
			swap(b[2], b[4]);
		}
		if (Y < 0) {
			Y = -Y;
			swap(b[1], b[3]);
		}
		printf("Case #%d: ", re);
		int total = 0;
		int cnt;
		for (cnt = 1; ; cnt++) {
			total += cnt;
			if (total >= X + Y && (total - X - Y) % 2 == 0) break;
		}
		// printf("total = %d cnt = %d\n", total, cnt);
		int x = X, y = Y;
		memset(a, 0, sizeof(a));
		if (Y > 0) {
			for (int i = cnt; i >= 1; i--) {
				if (X >= i) {
					X -= i;
					a[i] = 2;
				}
			}
			for (int i = cnt; i >= 1; i--) {
				if (a[i] == 0) {
					if (Y > 0) {
						Y -= i;
						a[i] = 1;
					} else {
						Y += i;
						a[i] = 3;
					}
				}
			}
		} else {
			for (int i = cnt; i >= 1; i--) {
				if (X > 0) {
					X -= i;
					a[i] = 2;
				} else {
					X += i;
					a[i] = 4;
				}
			}
		}
		for (int i = 1; i <= cnt; i++) {
			putchar(b[a[i]]);
		}
		puts("");
		/*
		if (X == 0 && Y == 0) puts("YES");
		else puts("NO");
		*/
	}
}
