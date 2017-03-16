#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <algorithm>

#define MAX_STR_NUM 256

int main(int argc, char* argv[])
{
	char filename[2][MAX_STR_NUM];
	sprintf(filename[0], "%s", "data.in");
	sprintf(filename[1], "%s.out", filename[0]);

	FILE* input = fopen(filename[0], "r");
	FILE* output = fopen(filename[1], "w");

	int T, N, S, p, t;
	fscanf(input, "%d", &T);
//	printf("%d\n", T);
	for(int i = 0; i < T; ++i)
	{
		fscanf(input, "%d %d %d", &N, &S, &p);
//		printf("%d %d %d\n", N, S, p);
		int cnt1 = 0, cnt2 = 0, bound = 3 * p - 2;
		for (int j = 0; j < N; ++j)
		{
			fscanf(input, "%d", &t);
//			printf("%d ", t);
			if (t >= bound) ++cnt1;
			else if (t >= 2 && t + 2 >= bound) ++cnt2;
		}
//		printf("\n\n");
		fprintf(output, "Case #%d: %d\n", i + 1, cnt1 + (cnt2 > S ? S : cnt2));
	}

	fclose(output);
	fclose(input);

//	system("pause");
	return 0;
}