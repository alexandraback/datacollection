/* 2016.4.16 Celicath */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stdint.h>

char line[10000];
char result[10000];

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;

	fscanf(fin, "%d", &T);


	for (int c_n = 1; c_n <= T; c_n++)
	{
		int n, j;
		fscanf(fin, "%s", line);

		int starting = 5000;
		int ending = 5000;
		result[starting] = line[0];
		
		for (int i = 1; line[i]; i++)
		{
			if (line[i] >= result[starting])
				result[--starting] = line[i];
			else result[++ending] = line[i];
		}
		result[++ending] = '\0';

		fprintf(fout, "Case #%d: %s\n", c_n, result + starting);
		printf("Case #%d: %s\n", c_n, result + starting);

	}
	return -0;
}
