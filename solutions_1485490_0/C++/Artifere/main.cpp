#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int motifsA[100], motifsB[100];
long long nbA[101], nbB[101];
int nbTests, N, M;
vector<int> pourA, pourB;

long long bestScore = 0;

void recur(int posA, int posB, long long curScore, long long nbLeftA, long long nbLeftB)
{
	//printf("%d %d\n", posA, posB);


	if (posA >= N || posB >= M)
	{
		bestScore = max(curScore, bestScore);
		/*if (curScore == -1)
		{
			for (int i = 0; i < pourA.size(); i++)
				printf("%d  ", pourA[i]);
			printf("\n");
			for (int i = 0; i < pourB.size(); i++)
				printf("%d  ", pourB[i]);
			printf("\n");
		}*/
	}

	else if (motifsA[posA] == motifsB[posB])
	{
		pourA.push_back(posA);
		pourB.push_back(posB);

		//printf("%d %d %lld %lld %lld\n", posA, posB, curScore, nbLeftA, nbLeftB);

		if (nbLeftA == nbLeftB)
			recur(posA+1, posB+1, curScore + nbLeftB, nbA[posA+1], nbB[posB+1]);
		else if (nbLeftA > nbLeftB)
		{
			//printf("%lld\n", nbLeftA-nbLeftB);
			recur(posA, posB+1, curScore + nbLeftB, nbLeftA-nbLeftB, nbB[posB+1]);
		}
		else
			recur(posA+1, posB, curScore + nbLeftA, nbA[posA+1], nbLeftB-nbLeftA);
		pourA.pop_back();
		pourB.pop_back();
	}

	else
	{
		recur(posA+1, posB, curScore, nbA[posA+1], nbLeftB);
		recur(posA, posB+1, curScore, nbLeftA, nbB[posB+1]);
	}
}



int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);


	scanf("%d", &nbTests);

	for (int test = 1; test <= nbTests/** ATTTTTTTTTTENTION**/; test++)
	{
		printf("Case #%d: ", test);
		bestScore = 0;

		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++)
			scanf("%lld %d", &nbA[i], &motifsA[i]);

		for (int i = 0; i < M; i++)
			scanf("%lld %d", &nbB[i], &motifsB[i]);
		//printf("N = %d, M = %d", N, M);

		recur(0, 0, 0, nbA[0], nbB[0]);
		printf("%lld\n", bestScore);
	}









    return 0;
}
