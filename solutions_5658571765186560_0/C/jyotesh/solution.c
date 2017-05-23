/*Ominous Omino*/

#include<stdio.h>

int main()
{
	int C, maxside, minside, R, t, T, X;
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D.out", "w", stdout);
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		scanf("%d %d %d", &X, &R, &C);
		printf("Case #%d: ", t);
		maxside = (R > C) ? R : C;
		minside = (R < C) ? R : C;
		if (X >= 7)
			puts("RICHARD");
		else if ((X > R) && (X > C))
			puts("RICHARD");
		else if ((R * C) % X != 0)
			puts("RICHARD");
		else if (((X + 1) / 2) > minside)
			puts("RICHARD");
		else if ((X == 1) || (X == 2) || (X == 3))
			puts("GABRIEL");
		else if (X == 4)
			puts((minside > 2) ? "GABRIEL" : "RICHARD");
		else if (X == 5)
			puts(((minside == 3) && (maxside == 5)) ? "RICHARD" : "GABRIEL");
		else if (X == 6)
			puts((minside > 3) ? "GABRIEL" : "RICHARD");
	}
	return 0;
}