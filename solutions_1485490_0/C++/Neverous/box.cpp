/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>
#include<vector>

int tests,
    boxes,
    toys,
    boxType[128],
    toyType[128];
long long int toyCount[128],
              boxCount[128],
              toyUsed;
std::pair<long long int, long long int> dp[128][128][2],
                                        max;

inline static const long long int MIN(const long long int &a, const long long int &b){return a>b?b:a;}
inline static const long long int MAX(const long long int &a, const long long int &b){return a<b?b:a;}

int main(void)
{
	scanf("%d", &tests);
	for(int t = 1; t <= tests; ++ t)
	{
		printf("Case #%d: ", t);
		scanf("%d %d", &boxes, &toys);
		for(int b = 1; b <= boxes; ++ b)
			scanf("%lld %d", &boxCount[b], &boxType[b]);

		for(int t = 1; t <= toys; ++ t)
			scanf("%lld %d", &toyCount[t], &toyType[t]);

		for(int t = 0; t <= toys; ++ t)
			for(int b = 0; b <= boxes; ++ b)
				for(int s = 0; s < 2; ++ s)
					dp[t][b][s] = std::make_pair(0, 0);

		//puts("");
		for(int t = 1; t <= toys; ++ t)
		{
			toyUsed = 0;
			for(int b = 1; b <= boxes; ++ b)
			{
				for(int q = 0; q < t; ++ q)
				{
					if(toyType[t] != boxType[b])
					{
						// UP
						if(dp[q][b][1].first > dp[t][b][1].first)
							dp[t][b][1] = dp[q][b][1];

						if(dp[q][b][0].first > dp[t][b][1].first)
							dp[t][b][1] = dp[q][b][0];
					}

					else
					{
						// UP
						if(dp[q][b][0].first + MIN(toyCount[t], boxCount[b] - dp[q][b][0].second) > dp[t][b][1].first)
						{
							dp[t][b][1] = dp[q][b][0];
							dp[t][b][1].first += MIN(toyCount[t], boxCount[b] - dp[q][b][0].second);
							dp[t][b][1].second += MIN(toyCount[t], boxCount[b] - dp[q][b][0].second);
						}

						if(dp[q][b][1].first + MIN(toyCount[t], boxCount[b] - dp[q][b][1].second) > dp[t][b][1].first)
						{
							dp[t][b][1] = dp[q][b][1];
							dp[t][b][1].first += MIN(toyCount[t], boxCount[b] - dp[q][b][1].second);
							dp[t][b][1].second += MIN(toyCount[t], boxCount[b] - dp[q][b][1].second);
						}
					}
				}

				dp[t][b][0] = dp[t][b][1];
				if(toyType[t] == boxType[b])
				{
					if(dp[t][b - 1][0].first >= dp[t][b - 1][1].first)
						max = dp[t][b - 1][0];

					else
						max = dp[t][b - 1][1];

					if(max.first + MIN(toyCount[t] - toyUsed, boxCount[b]) > dp[t][b][0].first)
					{
						dp[t][b][0] = max;
						dp[t][b][0].first += dp[t][b][0].second = MIN(toyCount[t] - toyUsed, boxCount[b]);
						toyUsed += dp[t][b][0].second;
					}

					else toyUsed = 0;
				}

				else
				{
					if(dp[t][b - 1][0].first > dp[t][b - 1][1].first)
						max = dp[t][b - 1][0];

					else
						max = dp[t][b - 1][1];

					if(max.first > dp[t][b][0].first)
						dp[t][b][0].first = max.first;

					toyUsed = 0;
				}

				//printf("(%3lld|%3lld/%3lld) ", toyUsed, dp[t][b][0].first, dp[t][b][1].first);
			}
			//puts("");
		}

		printf("%lld\n", MAX(dp[toys][boxes][0].first, dp[toys][boxes][1].first)); 

	}

	return 0;
}
