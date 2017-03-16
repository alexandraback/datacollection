#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {
		int X, R, C;
		scanf("%d%d%d", &X, &R, &C);
		if (R > C)
			swap(R, C);
		if (R * C % X) {
			printf("Case #%d: RICHARD\n", ++kase);
			continue;
		}
		if (X == 1 || X == 2) {
			printf("Case #%d: GABRIEL\n", ++kase);
			continue;
		}
		if (X == 3) {
			if (R == 1 && C == 3)
				printf("Case #%d: RICHARD\n", ++kase);
			else
				printf("Case #%d: GABRIEL\n", ++kase);
			continue;
		}
		if (X == 4) {
			if (R == 1 && C == 4 || R == 2 && C == 2 || R == 2 && C == 4)
				printf("Case #%d: RICHARD\n", ++kase);
			else
				printf("Case #%d: GABRIEL\n", ++kase);
			continue;
		}
	}
	return 0;
}