#include <iostream>
#include <stdio.h>

using namespace std;

double pBack(double p[], int len, int num, int word)
{
	double prob = 1.0;
	for(int i = 0; i < len - num; i++)
	{
		prob *= p[i];
	}
	return prob*(double)(num*2+word-len+1) + (1-prob)*(double)(num*2+word*2-len+2);
}

double calc(double p[], int a, int b)
{
	double min = b+2.0;
	for(int i = 0; i <=a; i++)
	{
		double prob = pBack(p, a, i, b);
		if(prob < min)
			min = prob;
	}
	return min;
}

int main(int argc, char* argv[])
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		double p[a];
		for(int j = 0; j < a; j++)
		{
			cin >> p[j];
		}
		printf("Case #%d: %.6f\n", i+1, calc(p, a, b));
	}
	return 0;
}