#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

using namespace std;

int scores[205];
double real_scores[205];

int main()
{
	freopen("A-large.in","r",stdin);
	FILE *out_fp = fopen("Al01.out","w");
	int T;
	scanf("%d", &T);
	for(int test = 1; test <= T; ++test)
	{
		int n;
		scanf("%d", &n);
		memset(scores, 0, sizeof(scores));
		memset(real_scores, 0, sizeof(real_scores));

		for (int  i = 0; i < n; ++i)
		{
			scanf("%d", &scores[i]);
			real_scores[i] = scores[i];
		}

		int sum = 0;
		for (int i = 0; i < n; ++i)
			sum += scores[i];

		double votes_percentage = 1;

		while (votes_percentage > 0.00000001)
		{
			double min = real_scores[0], min1 = real_scores[0];
			int min_counter = 0;
			for (int i = 0; i < n; ++i)
			{
				if (real_scores[i] < min)
					min = real_scores[i];
				if (real_scores[i] > min1)
					min1 = real_scores[i];
			}

			for (int i = 0; i < n; ++i)
			{
				if (real_scores[i] == min)
					++min_counter;
			}

			for (int i = 0; i < n; ++i)
			{
				if (real_scores[i] < min1 && real_scores[i] != min)
					min1 = real_scores[i];
			}

			if (min_counter == n)
			{
				double adder = votes_percentage * sum / n;
				for (int i = 0; i < n; ++i)
					real_scores[i] += adder;
				votes_percentage = 0;
			}
			else
			{
				double diff = min1 - min;
				if (votes_percentage * sum < diff * min_counter)
				{
					double adder = votes_percentage * sum / min_counter;
					for (int i = 0; i < n; ++i)
					{
						if (real_scores[i] == min)
							real_scores[i] += adder;
					}
					votes_percentage = 0;
				}
				else
				{
					for (int i = 0; i < n; ++i)
					{
						if (real_scores[i] == min)
							real_scores[i] += diff;
					}
					votes_percentage -= (diff * min_counter) / sum;
				}
				
			}
		}

		fprintf(out_fp, "Case #%d: ", test);
		
		for (int i = 0; i < n; ++i)
		{
			double votes = (real_scores[i] - scores[i]) / sum * 100;
			printf("%.8lf ", votes);
			fprintf(out_fp, "%.8lf ", votes);
		}
		fprintf(out_fp, "\n");
		printf("\n");
	}
	fclose(out_fp);
	return 0;
}