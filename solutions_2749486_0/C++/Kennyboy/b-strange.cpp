#include <cstdio>


int x, y;
char jump[506];

int abs(int a) { return a > 0 ? a : -a; }

void proc() {
	scanf("%d %d", &x, &y);

	for (int i = 1; i <= 500; i++) {
		// try to solve
		int cx = x, cy = y;
		for (int j = i; j > 0; j--) {
			if (abs(cx) > abs(cy)) {
				if (cx < 0) {
					jump[j] = 'W';
					cx += j;
				} else {
					jump[j] = 'E';
					cx -= j;
				}
			} else {
				if (cy < 0) {
					jump[j] = 'S';
					cy += j;
				} else {
					jump[j] = 'N';
					cy -= j;
				}
			}
//			printf("%d %d\n", cx, cy);
		}
//		printf("\n");

		// if success
		//     print, break
		if (cx == 0 && cy == 0) {
			for (int j = 1; j <= i; j++) {
				printf("%c", jump[j]);
			}
			break;
		}
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		proc();
	}

	return 0;
}
