#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int ab(int x){return (x<0)?-x:x;}

double solve()
{
	int N, X, Y;
	cin>>N>>X>>Y;

	int h = 1;
	int sum = 1;
	for(; sum+2*h+3<=N; sum+=(2*h+3), h+=2);

	int dist = (ab(X)+Y);
	if(dist<h)return 1.0;
	if(dist<(h+2))
	{
		int r = N - sum;
		if(r>(h+1))
		{
			int r1 = r - (h+1);
			if(Y<r1)
				return 1.0;
			else
			{
				r = r - 2*r1;
				long double delta = 0.5, result = 0;
				for(int i=r1; i<Y; ++i)
					delta *= 0.5;
				for(int i=Y; i<=h; ++i, delta *= 0.5)
				{
					result += delta;
				}
				return result;
			}
		}
		else
		{
			long double delta = 0.5, result = 0;
			for(int i=0; i<Y; ++i)
				delta *= 0.5;
			for(int i=Y; i<=h; ++i, delta *= 0.5)
			{
				result += delta;
			}
			return result;
		}
	}

	return 0.0;
}

int main()
{
	int Tests;
	cin>>Tests;

	for(int test_case = 1; test_case<=Tests; ++test_case)
	{
		printf("Case #%d: %.7f\n", test_case, solve());
	}

	return 0;
}