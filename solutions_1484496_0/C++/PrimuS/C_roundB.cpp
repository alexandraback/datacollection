#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

using namespace std;

int numbers[20];
const int SIZE = 1 << 20;


struct sum_el 
{
	int sum;
	int mask;
	bool operator<(const sum_el & s2)
	{
		return sum < s2.sum;
	}
};

sum_el sums[SIZE];

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	FILE *out_fp = fopen("Cs.out","w");
	int T;
	scanf("%d", &T);
	for(int test = 1; test <= T; ++test)
	{
		int n;
		scanf("%d", &n);
		memset(numbers, 0, sizeof(numbers));
		memset(sums, 0, sizeof(sums));

		for (int  i = 0; i < n; ++i)
			scanf("%d", &numbers[i]);

		int granz = 1 << 20;
		for (int i = 1; i < granz; ++i)
		{
			int sum = 0;
			for (int j = 0; j < n; ++j)
			{
				if ((1 << j) & i)
					sum += numbers[j];
			}
			sums[i].sum = sum;
			sums[i].mask = i;
		}

		sort(sums + 1, sums + SIZE);
		fprintf(out_fp, "Case #%d:\n", test);

		int flag = 0;
		for (int i = 1; i < SIZE - 1; ++i)
		{
			if (sums[i].sum == sums[i + 1].sum)
			{
				flag = 1;
				for (int j = 0; j < n; ++j)
				{
					if ((1 << j) & sums[i].mask)
					{
						fprintf(out_fp, "%d ", numbers[j]);
						printf("%d ", numbers[j]);
					}
				}
				fprintf(out_fp, "\n");
				printf("\n");
				for (int j = 0; j < n; ++j)
				{
					if ((1 << j) & sums[i + 1].mask)
					{
						fprintf(out_fp, "%d ", numbers[j]);
						printf("%d ", numbers[j]);
					}
				}
				fprintf(out_fp, "\n");
				printf("\n");
				break;
			}
		}

		if (!flag)
		{
			fprintf(out_fp, "Impossible\n");
			printf("Impossible\n");
		}
	}
	fclose(out_fp);
	return 0;
}