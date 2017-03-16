#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

#define MAX_SIZE 10

bool generateSet(int N, int M, int i, int mSet[], int product[], int K, int ans[]);
void guess(int N, int M, int product[], int K, int ans[]);

int main(void)
{
	int T, caseId = 1, R, N, M, K, ans[MAX_SIZE], num;
	int product[MAX_SIZE];

	scanf("%d", &T);
 
	scanf("%d %d %d %d", &R, &N, &M, &K);

	printf("Case #1:\n");
	for(int i = 0 ; i < R; i++)
	{
		for(int j = 0; j < K; j++) {
			scanf("%d", &product[j]);
		}

		guess(N, M, product, K, ans);

		for(int j = 0; j < N; j++)
			printf("%d", ans[j]);
		printf("\n");
	}
	return 0;
}

void guess(int N, int M, int product[], int K, int ans[])
{
	int mSet[MAX_SIZE];

	generateSet(N, M, 0, mSet, product, K, ans);
			
}

bool generateSet(int N, int M, int i, int mSet[], int product[], int K, int ans[])
{
	if(i == N)
	{
		set<int> subsetProduct;

		subsetProduct.insert(1);
		// Check all subsets products
		// Assume N <= 3
		for(int k = 0; k < N; k++)
			subsetProduct.insert(mSet[k]);

		if(N <= 2)
		{
			subsetProduct.insert(mSet[0] * mSet[1]);
		}

		if(N == 3)
		{
			subsetProduct.insert(mSet[0] * mSet[1]);
			subsetProduct.insert(mSet[0] * mSet[2]);
			subsetProduct.insert(mSet[1] * mSet[2]);
			subsetProduct.insert(mSet[0] * mSet[1] * mSet[2]);
		}

		for(int k = 0; k < K; k++)
			if(subsetProduct.find(product[k]) == subsetProduct.end())
				return false;

		for(int k = 0; k < N; k++)
			ans[k] = mSet[k];
		return true;
	}
	
	for(int k = 2; k <= M; k++)
	{
		mSet[i] = k;

		if(generateSet(N, M, i + 1, mSet, product, K, ans))
			break;
	}
}
