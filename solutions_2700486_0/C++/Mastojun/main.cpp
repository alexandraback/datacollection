#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <list>
#include <climits>

using namespace std;

int N, X, Y;
int perfect;
int alwaysFilled;
double result[10001];

bool isInPerfectArea()
{
	return Y + abs(X) < perfect+1;
}

bool isAlwaysFilledArea()
{
	return Y < alwaysFilled && Y + abs(X) == perfect+1;
}

bool isOutOfRange()
{
	if(Y + abs(X) > perfect+1) return true;
	return Y >= alwaysFilled + N;
}

double ncr(int n, int r)
{
	double result = 1;
	for(int i = 0; i < r; i++)
	{
		result *= n-i;
		result /= (i+1);
	}

	return result;
}

double solve()
{
	if(isInPerfectArea()) return 1.0;
	if(isAlwaysFilledArea()) return 1.0;
	if(isOutOfRange()) return 0.0;

	for(int i = 0; i < N; i++){
		result[i] = 0;
	}

	double all = pow(2, N);

	for(int i = 0; i <= N; i++)
	{
		double that = ncr(N, i)/all;
		for(int j = 0; j < i; j++)
		{
			result[j] += that;
		}
	}

	return result[Y-alwaysFilled];
}

int main()
{	
	int C;
	scanf("%d", &C);

	while(C --> 0)
	{
		//input
		scanf("%d %d %d", &N, &X, &Y);
		perfect = 1;
		for(;;perfect+=2)
		{
			if(perfect*(perfect+1)/2 > N)
			{
				perfect -= 2;
				N -= perfect*(perfect+1)/2;
				break;
			}
		}
		alwaysFilled = 0;
		if(N > perfect)
		{
			alwaysFilled = N-(perfect+1);
			N = N-alwaysFilled*2;
		}

		static int Case = 1;
		printf("Case #%d: %lf\n", Case++, solve());
	}

	return 0;
}
