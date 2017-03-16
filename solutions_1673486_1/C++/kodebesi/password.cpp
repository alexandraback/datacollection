/*
 * password.cpp
 *
 *  Created on: Apr 27, 2012
 *      Author: firat
 */

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int A, B;
		cin >> A;
		cin >> B;
		double* p = new double[A];
		for(int j = 0; j < A; j++)
		{
			cin >> p[j];
		}

		double prod1 = 1, prod2 = 1, prod3 = 1;
		for(int j = 0; j < A; j++)
		{
			prod1 *= p[j];
			if(j == A-1)
			{
				prod2 *= 1-p[j];
				prod3 *= 1-p[j];
			}
			else if(j == A-2 && A >= 2)
			{
				prod2 *= p[j];
				prod3 *= 1-p[j];
			}
			else
			{
				prod2 *= p[j];
				prod3 *= p[j];
			}
		}
		//strategy 1
		double min;
		double st1 = (B-A+1)*prod1 + (B-A+1+B+1)*(1-prod1);
		min = st1;
		double st2 = (B-A+3)*(prod1+prod2) + (B-A+2+B+1+1)*(1-prod1-prod2);
		if(st2 <  min)
		{
			min = st2;
		}
		double st3 = (B-A+5)*(prod1 + prod2 + prod3) + (B-A+3+B+1+2)*(1 - (prod1 + prod2 + prod3));
		if(A>= 2 && st3 < min)
		{
			min = st3;
		}
		double st4 = B+2;
		if(st4 < min)
		{
			min = st4;
		}
		printf("Case #%d: %.6f\n", i+1, min);
		delete[] p;
	}
	return 0;
}




