#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <list>
#include <map>

#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int t_index = 0; t_index < T; t_index++)
	{
		int N;
		scanf("%d", &N);

		vector<int> s(N);
		double sum = 0;

		for(int i = 0; i < N; i++)
		{
			scanf("%d", &s[i]);

			sum += s[i];
		}

		vector<double> diff(N - 1);
		double diffsum = 0;

		for(int i = 1; i < N; i++)
		{
			diff[i - 1] = double(s[i] - s[0]) / sum;

			diffsum += diff[i - 1];
		}

		double first = (1 + diffsum) / N;

		vector<double> answers(N);

		answers[0] = first;

		for(int i = 1; i < N; i++)
		{
			answers[i] = first - diff[i - 1];
		}

		double sum2 = 0;
		int count = 0;
		vector<bool> flags(N);
		for(int i = 0; i < N; i++)
		{
			if(answers[i] <= 0)
			{
				sum2 -= answers[i];

				flags[i] = true;
				count++;
			}
		}

		for(int i = 0; i < N; i++)
		{
			if(flags[i])
			{
				answers[i] = 0;
			}
			else
			{
				answers[i] -= sum2 / (N - count);
			}
		}

		printf("Case #%d: %lf", t_index + 1, answers[0] * 100);

		for(int i = 1; i < N; i++)
		{
			printf(" %lf", answers[i] * 100);
		}
		printf("\n");

		vector<int> votes(N);
		for(int i = 0; i < N; i++)
		{
			votes[i] = s[i] + sum * answers[i];
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}