#include <stdio.h>
#include <string.h>

int main() {
	int T;
	freopen("B-small-attempt0 (6).in", "r", stdin);
	freopen("w.txt", "w", stdout); 
	scanf("%d", &T);
	for (int re = 1; re <= T; re++) {
		int X, Y;
		scanf("%d%d", &X, &Y);
		printf("Case #%d: ", re);
		if (X < 0) {
			for (int i = 0; i < -X; i++) {
				printf("EW");
			}
		} else {
			for (int i = 0; i < X; i++) {
				printf("WE");
			}
		}
		if (Y < 0) {
			for (int i = 0; i < -Y; i++) {
				printf("NS");
			}
		} else {
			for (int i = 0; i < Y; i++) {
				printf("SN");
			}
		}
		puts("");
	}
}
