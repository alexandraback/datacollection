#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <list>
#include <map>

#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		int N;
		scanf("%d", &N);
		
		vector<int> S(N);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &S[i]);
		}

		vector<pair<int, int>> sums;

		for(int mask = 0; mask < 1048576; mask++)
		{
			int sum = 0;
			for(int k = 0; k < 20; k++)
			{
				if( mask & ( 1 << k ) )
				{
					sum += S[k];
				}
			}
			sums.push_back(make_pair(sum, mask));
		}

		sort(sums.begin(), sums.end());

		printf("Case #%d:\n", t);

		int i = 1;
		for(i = 1; i < 1048576; i++)
		{
			if(sums[i].first == sums[i - 1].first)
			{
				bool first = true;
				for(int k = 0; k < 20; k++)
				{
					if( sums[i - 1].second & ( 1 << k ) )
					{
						if(first)
						{
							printf("%d", S[k]);
							first = false;
						}
						else
						{
							printf(" %d", S[k]);
						}
					}
				}
				printf("\n");

				first = true;
				for(int k = 0; k < 20; k++)
				{
					if( sums[i].second & ( 1 << k ) )
					{
						if(first)
						{
							printf("%d", S[k]);
							first = false;
						}
						else
						{
							printf(" %d", S[k]);
						}
					}
				}
				printf("\n");

				break;
			}
		}
		if(i == 1048576)
		{
			printf("Impossible\n");
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}