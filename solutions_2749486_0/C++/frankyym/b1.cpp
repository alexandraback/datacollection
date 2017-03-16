#include <cstdio>
#include <iostream>
using namespace std;

int T;

void gen(int x, int& counter, string dir) {
	int shift = 0;
	if (x < 0) {
		x = -x;
		shift = 1;
	}
	if (x == 0) return;

	for (int i=0; i<x; ++i) {
		printf("%c%c", dir[1^shift], dir[0^shift]);
		counter += 2;
	}
}

int main() {
	scanf("%d", &T);
	for (int t=0; t<T; ++t) {
		int x, y;
		scanf("%d%d", &x, &y);

		int counter = 1;
		printf("Case #%d: ", t+1);
		gen(x, counter, "EW");
		gen(y, counter, "NS");
		printf("\n");
	}
	return 0;
}
