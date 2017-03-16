/*
ALGORITHM

WHILE (WHILE BUYING 1 MORE FARM MAKES YOU GET TO THE GOAL FASTER)
	BUY IT

END
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <cmath>
#include <queue>
using namespace std;


double buy_more(double C, double F, double X, double cookie_rate)
{
	double ret = 0;
	ret += C / cookie_rate;

	cookie_rate += F;
	ret += X / cookie_rate;

	return ret;
}

double current(double C, double F, double X, double cookie_rate)
{
	double ret = 0;
	ret += X / cookie_rate;

	return ret;
}

void input()
{

	double C, F, X;
	scanf("%lf%lf%lf", &C, &F, &X);

	double cookie_rate = 2.0;
	double result = 0;

	while (buy_more(C, F, X, cookie_rate) < current(C, F, X, cookie_rate))
	{
		result += C / cookie_rate;
		cookie_rate += F;
	}

	result += X / cookie_rate;

	printf("%.7lf\n", result);
}

int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int T;
	scanf("%d", &T);

	for (int test = 1; test <= T; ++test)
	{
		printf("Case #%d: ", test);
		input();
	}

	return 0;
}