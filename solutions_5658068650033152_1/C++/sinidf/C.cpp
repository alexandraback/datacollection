#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <map>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
typedef long long ll;

int N, M, K;

int main()
{
	int n_case = 0;
	scanf("%d", &n_case);
	for (int ca = 1; ca <= n_case; ca++)
	{
		scanf("%d%d%d", &N, &M, &K);
		if (N > M) swap(N, M);
		int ans = N * M;
		if (K <= 4)
		{
			ans = K;
		}
		else if (N <= 2)
		{
			ans = K;
		}
		else
		{
			int Largest = 0;
			if (N & 1)
			{
				Largest = ((N + 1) / 2 + (N + 1) / 2 - 1) * (N + 1) / 2 - (N + 1) / 2 + 1;
			}
			else
			{
				Largest = (N / 2 + N / 2 - 1) * (N / 2 + 1) - (N / 2 - 1);
			}
			if (K < Largest) 
			{
				for (int i = 3; i * i <= K; i++)
				{
					int j = (K + i - 1) / (i + i - 1);
					int m = (K + i - 1) % (i + i - 1);
					ans = min(ans, i * j + (m + i - 2) / (max(i, j) - 1));
				}
			}
			else if (K == Largest)
			{
				ans = ((N + 2) / 2) * ((N + 1) / 2);
			}
			else if (N & 1)
			{
				ans = ((N + 2) / 2) * ((N + 1) / 2);
				K -= Largest;
				int now = (N + 1) / 2;
				int Tim = M - N;
				while (Tim && K > 0)
				{
					K -= now - 1;
					ans++;
					if (K <= 0) break;
					K -= now;
					ans++;
					Tim--;
				}
				int limit = 0;
				while (K > 0)
				{
					ans++;
					limit++;
					K -= now - 1;
					if (limit == 4)
					{
						limit = 0;
						now--;
					}
				}
			}
			else
			{
				ans = ((N + 2) / 2) * ((N + 1) / 2);
				K -= Largest;
				if (K > 0)
				{
					K -= N / 2;
					ans++;
				}
				if (K > 0)
				{
					K -= N / 2;
					ans++;
				}
				int now = N / 2;
				int Tim = M - N;
				while (Tim && K > 0)
				{
					K -= now;
					ans++;
					if (K <= 0) break;
					K -= now;
					ans++;
					Tim--;
				}
				int limit = 0;
				while (K > 0)
				{
					ans++;
					limit++;
					K -= now - 1;
					if (limit == 4)
					{
						limit = 0;
						now--;
					}
				}
			}
		}
		printf("Case #%d: %d\n", ca, ans);
	}
	return 0;
}
