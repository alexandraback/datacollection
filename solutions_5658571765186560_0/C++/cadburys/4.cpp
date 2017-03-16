#include <cstdio>

int T, X, R, C;
bool rich;

int main() {
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t) {
		scanf("%d%d%d", &X, &R, &C);
		rich = true;
		switch(X) {
			case 1:
				rich = false;
				break;
			case 2:
				rich = (R * C) % 2 == 1;
				break;
			case 3:
				if((R % 3 == 0 && C >= 2) || (R >= 2 && C % 3 == 0))
					rich = false;
				break;
			case 4:
				if((R * C) % 4 == 0 && ((R >= 3 && C >= 4) || (R >= 4 && C >= 3)))
					rich = false;
			default:
				rich = true;
		}
		printf("Case #%d: ", t);
		if(rich)
			printf("RICHARD\n");
		else
			printf("GABRIEL\n");
	}
	return 0;
}
