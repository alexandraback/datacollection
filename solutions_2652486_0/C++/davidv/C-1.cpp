#include <cstdio>
#include <map>

using namespace std;

map<int, int> prodCounts;
int curGuess[12];
int bestGuess[12];
long long bestProb;
int observations[12];
int N, M, K, R;
int fac[] = {1,1,2,6,24,120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};
void recUpdate(int idx, int prod)
{
	if (idx == N)
	{
		prodCounts[prod]++;
		return;
	}
	
	recUpdate(idx+1, prod);
	recUpdate(idx+1, prod*curGuess[idx]);
}

void updCounts()
{
	prodCounts.clear();
	
	recUpdate(0, 1);
}

void itersol(int idx, int lv, int mult)
{
	if (idx == N)
	{
		updCounts();
		long long curProb = mult;
		for (int i=0; i<K; i++)
			curProb *= prodCounts[observations[i]];
		
		if (curProb > bestProb)
		{
			bestProb = curProb;
			for (int i=0; i<N; i++)
				bestGuess[i] = curGuess[i];
		}
		return;
	}
	
	if (lv > M)
		return;
	
	for (; lv < M; lv++)
	{
		for (int i=1; idx+i<=N; i++)
		{
			curGuess[idx+i-1] = lv;
			itersol(idx+i, lv+1, mult/fac[i]);
		}
	}
	
	int l = N-idx;
	for (; idx < N; idx++)
	{
		curGuess[idx] = M;
	}
	itersol(N, M+1, mult/fac[l]);
}

void doCase()
{
	for (int i=0; i<K; i++)
	{
		scanf("%d", &observations[i]);
	}
	
	for (int i=0; i<N; i++)
	{
		bestGuess[i] = 0;
	}
	bestProb = 0;
	
	itersol(0,2,fac[N]);
	
	for (int i=0; i<N; i++)
	{
		printf("%d", bestGuess[i]);
	}
	printf("\n");
}

int main()
{
	scanf("%*d %d %d %d %d", &R, &N, &M, &K);
	
	printf("Case #1:\n");
	for (int i=0; i<R; i++)
		doCase();
		
	return 0;
}
