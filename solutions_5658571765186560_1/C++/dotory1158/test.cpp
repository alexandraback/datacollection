#include <stdio.h>
#include <algorithm>
void YES(int x) {
	printf("Case #%d: GABRIEL\n", x);
	return;
}
void NO(int x) {
	printf("Case #%d: RICHARD\n", x);
	return;
}
int main() {
	freopen("D-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, X, R, C;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		scanf("%d %d %d", &X, &R, &C);
		if(R>C) std::swap(R, C);
		if((R*C)%X != 0) {
			NO(t);
			continue;
		}
		if(X >= 7) {
			NO(t);
			continue;
		}
		if(X <= 2) {
			YES(t);
			continue;
		}
		if(X == 3) {
			if(R >= 2) YES(t);
			else NO(t);
			continue;
		}
		if(X == 4) {
			if(R >= 3) YES(t);
			else NO(t);
			continue;
		}
		if(X == 5) {
			if(R == 3 && C >= 10) YES(t);
			else if(R >= 4) YES(t);
			else NO(t);
			continue;
		}
		if(X == 6) {
			if(R <= 3) NO(t);
			else YES(t);
			continue;
		}
	}
	return 0;
}