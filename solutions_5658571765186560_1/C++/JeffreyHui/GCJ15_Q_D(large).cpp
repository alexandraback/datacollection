#include <cstdio>
int T, X, R, C;
int main (){
	freopen("D-large.in", "r", stdin);
	freopen("D-large.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		scanf("%d %d %d", &X, &R, &C);
		if ((R < X && C < X) || (R * C) % X)
			printf("Case #%d: RICHARD\n", i);
		else if (X <= 2)
			printf("Case #%d: GABRIEL\n", i);
		else if (X >= 7)
			printf("Case #%d: RICHARD\n", i);
		else if (X == 3 && (R == 1 || C == 1))
			printf("Case #%d: RICHARD\n", i);
		else if (X == 4 && (R <= 2 || C <= 2))
			printf("Case #%d: RICHARD\n", i);
		else if (X == 5 && (R <= 3 || C <= 3))
			printf("Case #%d: RICHARD\n", i);
		else if (X == 6 && (R <= 3 || C <= 3))
			printf("Case #%d: RICHARD\n", i);
		else 
			printf("Case #%d: GABRIEL\n", i);
	}
	return 0;
}
