#include <cstdio>
void deal(int T) {
	int x, y;
	char first, second;
	scanf("%d%d", &x, &y);
	printf("Case #%d: ", T + 1);
	if (x > 0) {
		first = 'W';
		second = 'E';
	} else {
		first = 'E';
		second = 'W';
		x = -x;
	}
	for (int i = 0; i < x; i++) {
		printf("%c", first);
		printf("%c", second);
	}
	if (y > 0) {
		first = 'S';
		second = 'N';
	} else {
		first = 'N';
		second = 'S';
		y = -y;
	}
	for (int i = 0; i < y; i++) {
		printf("%c", first);
		printf("%c", second);
	}
	printf("\n");
}
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		deal(i);
	}
	return 0;
}
