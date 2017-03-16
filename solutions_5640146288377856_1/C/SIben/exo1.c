#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Global variables are da shit bcs I'm lazy
int R, C, W, size;

int result() {
	if (W == 1) return C*R;
	if (W == C) return R+W-1;
	if (C%W == 0) return C/W*R+W-1;
	return C/W*R+W;
}

int main() {

	int i, T;
	scanf("%d", &T);

	for(i = 0; i < T; i++) {
		scanf("%d %d %d", &R, &C, &W);
		int tab[R][C];
		printf("Case #%d: %d\n", i+1, result());
	}
}
