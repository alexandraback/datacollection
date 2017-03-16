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
long long int P, Q;
char merde;

long long int pgcd(long long int a, long long int b)
{
	if(b == 0)
		return a;
	return pgcd(b, a%b);
}

void computeAnswer()
{
	for(int iTest = 1; iTest <= nbTests; ++iTest)
	{
		printf("Case #%d: ", iTest);
		scanf("%lld %c%lld", &P, &merde, &Q);
		long long int generation = 1, curDenum = 2;
		long long int diviseur = pgcd(P, Q);
		P /= diviseur;
		Q /= diviseur;
		if(log2(Q) - (long long int)log2(Q))
			printf("impossible\n");
		else
		{
			while(Q > P * curDenum)
			{
				//printf("%lld < %lld\n", Q, P * curDenum);
				++generation;
				curDenum *= 2;
			}
			printf("%lld\n", generation);
		}
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
