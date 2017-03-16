#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <iostream>
#include <functional>

using namespace std;

int E, R, N;
int V[11000];

void Work(int Case)
{
	scanf("%d%d%d", &E, &R, &N);
	for (int i = 0; i < N; i ++)
		scanf("%d", &V[i]);

	if (R >= E)
		R = E;
	long long Ans = 0, curE = E;
	for (int i = 0; i < N; i ++)
	{
		int t = -1;
		for (int j = i + 1; j < N; j ++)
			if (V[j] >= V[i])
			{
				t = j;
				break;
			}
		if (t == -1)
		{
			Ans += (long long) V[i] * curE;
			curE = R;
			continue;
		}
		// transfer
		long long overflow = curE + R * (t - i) - E;
		if (overflow > 0)
		{
			long long transfer = min(overflow, curE);
			Ans += (long long) V[i] * transfer;
			curE -= transfer;
		}
		curE += R;
		if (curE > E)
			curE = E;
	}
	
	printf("Case #%d: %I64d\n", Case, Ans);
}

int main()
{
	freopen("B-small.in", "r", stdin);
	freopen("B-small.out", "w", stdout);

	int Cases;
	scanf("%d", &Cases);
	for (int Case = 1; Case <= Cases; Case ++)
		Work(Case);
	return 0;
}