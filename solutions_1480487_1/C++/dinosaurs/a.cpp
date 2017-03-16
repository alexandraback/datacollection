#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int MAXN = 222;
const long double epsilon = 1.0e-10;

int T, N, S[MAXN], ssum;

bool good(int cur, long double percentage)
{
	long double remaining = 1.0 - percentage;
	long double targ_score = S[cur] + ssum * percentage;
	for(int i = 0; i < N; i++)
		if(i != cur)
			remaining -= max((long double) 0.0, (targ_score - S[i]) / ssum);
	return remaining < 0;
}

int main()
{
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d", &N);
		ssum = 0;
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &S[i]);
			ssum += S[i];
		}
		printf("Case #%d:", t);
		for(int i = 0; i < N; i++)
		{
			long double low = 0.0, high = 1.0;
			while(high - low > epsilon)
			{
				long double guess = (low + high) / 2.0;
				if(good(i, guess))
					high = guess;
				else
					low = guess;
			}
			printf(" %.8Lf", (low + high) / 2.0 * 100.0);
		}
		printf("\n");
	}
	return 0;
}
