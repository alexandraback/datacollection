// PasswordProblem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	cout.setf(ios::fixed,ios::floatfield);
	cin.precision(6);
	int n, a, b;
	double *c = new double[100001];
	double *r = new double[100001];
	double min, keys;
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		cin>>a>>b;
		min = 2 + b;
		for (int j = 0; j < a; j++)
		{
			cin>>c[j];
			if (j)
				c[j] *= c[j - 1];
			keys = (a - j - 1) + c[j] * (b - j) + (1 - c[j]) * (b - j + b + 1);
			min = keys < min ? keys : min;
		}
		cout<<"Case #"<<i<<": "<<min<<endl;
	}
	delete[] c;
	return 0;
}

