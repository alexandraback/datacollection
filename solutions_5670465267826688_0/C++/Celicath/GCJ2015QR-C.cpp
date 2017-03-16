/* 2015.4.11 Celicath */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stdint.h>
#include <iostream>

int mult[][8] =
{
	{ 0, 1, 2, 3, 4, 5, 6, 7 },
	{ 1, 4, 3, 6, 5, 0, 7, 2 },
	{ 2, 7, 4, 1, 6, 3, 0, 5 },
	{ 3, 2, 5, 4, 7, 6, 1, 0 },
	{ 4, 5, 6, 7, 0, 1, 2, 3 },
	{ 5, 0, 7, 2, 1, 4, 3, 6 },
	{ 6, 3, 0, 5, 2, 7, 4, 1 },
	{ 7, 6, 1, 0, 3, 2, 5, 4 }
};

char line[10005];

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;

	fscanf(fin, "%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		int L,X;
		fscanf(fin, "%d%d\n", &L, &X);
		int result = 0;
		int cur = 0;

		for (int i = 0; i < L; i++)
		{
			fscanf(fin, "%c", line + i);
			int k = line[i] - 'i' + 1;
			cur = mult[cur][k];
		}
		if (cur == 0)
			goto hell;
		else if (cur == 4)
		{
			if (X % 2 == 0) goto hell;
		}
		else if (X % 4 != 2) goto hell;

		cur = 0;
		int phase = 0;
		int Y = std::min(X, 8);
		for (int i = 0; i < Y; i++)
			for (int j = 0; j < L; j++)
			{
				int k = line[j] - 'i' + 1;
				cur = mult[cur][k];
				if (cur == 1) phase = 1;
				else if (cur == 3 && phase == 1)
					goto done;
			}

		goto hell;
	done:

		fprintf(fout, "Case #%d: YES\n", c_n);
		printf("Case #%d: YES\n", c_n);
		continue;

	hell:
		fprintf(fout, "Case #%d: NO\n", c_n);
		printf("Case #%d: NO\n", c_n);
	}
	return -0;
}
