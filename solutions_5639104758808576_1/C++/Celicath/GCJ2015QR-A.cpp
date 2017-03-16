/* 2015.4.11 Celicath */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stdint.h>
#include <iostream>

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;

	fscanf(fin, "%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		int S;
		fscanf(fin, "%d\n", &S);
		int result = 0;
		int cur = 0;
		for (int i = 0; i <= S; i++)
		{
			char c;
			fscanf(fin, "%c", &c);
			int k = c - '0';
			cur += k - 1;
			if (cur < 0)
			{
				result -= cur;
				cur = 0;
			}
		}

		fprintf(fout, "Case #%d: %d\n", c_n, result);
		printf("Case #%d: %d\n", c_n, result);
	}
	return -0;
}
