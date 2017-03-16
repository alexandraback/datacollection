#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_SIZE 100
#define MAX_E 10

int dp(int e, int ind, int E, int R, int val[], int N, int memoTable[][MAX_SIZE]);

int main(void)
{
	int E, R, T, val[MAX_SIZE], N, caseId = 1;
	int memoTable[MAX_E][MAX_SIZE];

	scanf("%d", &T);
	while(caseId <= T)
	{
		scanf("%d %d %d", &E, &R, &N);

		for(int i = 0; i < N; i++)
			scanf("%d", &val[i]);

		memset(memoTable, -1, MAX_E * MAX_SIZE * sizeof(int));

		printf("Case #%d: %d\n", caseId, dp(E, 0, E, R, val, N, memoTable));
		caseId++;;
	}

	return 0;
}

int dp(int e, int ind, int E, int R, int val[], int N, int memoTable[][MAX_SIZE])
{
	if(e < 0)
		return 0;
	if(ind >= N)
		return 0;

	if(memoTable[e][ind] >= 0)
		return memoTable[e][ind];

	int max = 0, gain;
	for(int invest = 0; invest <= e; invest++)
	{
		int newE = e - invest + R;
		if(newE > E)
			newE = E;
		gain = val[ind] * invest + dp(newE, ind + 1, E, R, val, N, memoTable);

		if(gain > max)
			max = gain;
	}

	memoTable[e][ind] = max;

	return max;
}
