#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double C, F, X;

double ntime(int n)
{
	double res = 0;
	for (int i = 0; i < n; i++) res += C / (2 + i * F);
	res += X / (2 + n * F);
	return res;
}

double work()
{
	scanf("%lf%lf%lf", &C, &F, &X);
	int n = max((int)floor(X/C - 2/F), 0);
	return ntime(n);
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: %.8lf\n", i, work());
	}
	
	return 0;
}

