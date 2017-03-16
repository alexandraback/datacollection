#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

bool isSureToSurvive(int hisScore, const vector<int>& others, double got)
{
	int sum = hisScore;
	for (int i =0; i < others.size(); i++)
	{
		sum += others[i];
	}

	double accounted = got;
	for (int i = 0; i < others.size(); i++)
	{
		double needed = max(0.0, (hisScore + got*sum) - others[i]);
		accounted += needed/sum;
	}

	return accounted >= 1.0;
}

int main()
{
	int lz;
	scanf("%d", &lz);
	for(int tcase = 1; tcase <= lz; tcase++)
	{
		int n;
		scanf("%d", &n);
		vector<int> contestants(n);
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &contestants[i]);
		}

		printf("Case #%d: ", tcase);
		for (int i = 0; i < n; i++)
		{
			int hisScore = contestants[i];

			vector<int> scores = contestants;
			swap(scores[i], scores[(int)scores.size() - 1]);
			scores.pop_back();
			assert((int)scores.size() + 1 == (int)contestants.size());

			double low = 0.0;
			double high = 1.0;
			for (int it = 0; it < 200; it++)
			{
				double shot = (low + high)/2;
				if (isSureToSurvive(hisScore, scores, shot))
				{
					high = shot;
				}
				else
				{
					low = shot;
				}
			}

			printf("%.10lf", high*100);

			if (i == n-1)
			{
				printf("\n");
			}
			else
			{
				printf(" ");
			}
		}
	}
	return 0;
}
