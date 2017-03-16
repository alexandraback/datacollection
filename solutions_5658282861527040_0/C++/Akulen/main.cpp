#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int nbTests;
int A, B, K;

void computeAnswer()
{
	for(int iTest = 1; iTest <= nbTests; ++iTest)
	{
		long long int total = 0;
		scanf("%d%d%d", &A, &B, &K);
		for(int i = 0; i < A; ++i)
			for(int j = 0; j < B; ++j)
				if((i&j) < K)
					++total;
		printf("Case #%d: %lld\n", iTest, total);
	}
}

void displayAnswer()
{

}

void readInput()
{
	/*
	freopen("test.in", "r", stdin);
	/*/
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	//*/
	scanf("%d", &nbTests);
}

int main()
{
	readInput();
	computeAnswer();
	displayAnswer();
	return 0;
}
