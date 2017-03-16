#include <cstdio>

int main(void) {
	int nbTests;
	scanf("%d", &nbTests);
	for (int iTest = 0; iTest < nbTests; iTest++) {
		int xbut, ybut;
		scanf("%d%d", &xbut, &ybut);
		int x = 0, y = 0;
		printf("Case #%d: ", iTest+1);
		while (x < xbut) {
			printf("WE");
			x++;
		}
		while (x > xbut) {
			printf("EW");
			x--;
		}
		while (y < ybut) {
			printf("SN");
			y++;
		}
		while (y > ybut) {
			printf("NS");
			y--;
		}
		printf("\n");
	}
}
