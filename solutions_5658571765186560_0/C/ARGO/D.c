#include <stdio.h>

int X, R, C;

int main()
{
	int T, t, ans;
	char answer[2][10] = {"RICHARD", "GABRIEL"};
	FILE* fp = fopen("D-small.out", "w");

	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		scanf("%d %d %d", &X, &R, &C);
		if(X == 1) {
			ans = 1;
		}
		else if(X == 4) {
			if(R * C == 12 || R * C == 16)	ans = 1;
			else	ans = 0;
		}
		else if(X == 2) {
			if((R * C) % 2 == 1)	ans = 0;
			else	ans = 1;
		}
		else if(X == 3) {
			if((R * C == 6 || R * C == 9) || (R * C == 12)) {
				ans = 1;
			}
			else {
				ans = 0;
			}
		}
		fprintf(fp, "Case #%d: %s\n", t, answer[ans]);
	}
	fclose(fp);
	return 0;
}
