#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double process()
{
	int a, b;
	scanf("%d %d", &a, &b);
	double* p = new double[a];
	double* ap = new double[a];
	ap[0] = 1.;
	for(int i = 0; i < a; i++)
	{
		scanf("%lf", &p[i]);
		ap[i+1] = ap[i] * p[i];
	}
	double key = b+2;
	for(int i = 0; i <= a; i++)
	{
		int bs = a-i;
		double exp = (2*bs+b-a+1)*ap[i] + (2*bs+2*b-a+2)*(1-ap[i]);
		key = min(key, exp);
	}
	return key;
}

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
		printf("Case #%d: %.6lf\n", i+1, process());
	return 0;
}
