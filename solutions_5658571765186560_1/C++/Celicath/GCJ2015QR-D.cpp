/* 2015.4.11 Celicath */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stdint.h>
#include <iostream>

char line[10005];

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;

	fscanf(fin, "%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		int X, R, C;
		fscanf(fin, "%d%d%d", &X, &R, &C);

		bool result;
		if (X == 1)
			result = true;
		else if (X == 2)
			result = ((R * C) % 2 == 0);
		else if (X == 3)
			result = ((R * C) % 3 == 0 && R > 1 && C > 1);
		else if (X == 4)
			result = ((R * C) % 4 == 0 && R > 2 && C > 2);
		else if (X == 5)
			result = ((R * C) % 5 == 0 && R > 3 && C > 3);
		else if (X == 6)
			result = ((R * C) % 6 == 0 && R > 3 && C > 3);
		else
			result = false;

		if (result)
		{
			fprintf(fout, "Case #%d: GABRIEL\n", c_n);
			printf("Case #%d: GABRIEL\n", c_n);
		}
		else
		{
			fprintf(fout, "Case #%d: RICHARD\n", c_n);
			printf("Case #%d: RICHARD\n", c_n);
		}
	}
	return -0;
}
