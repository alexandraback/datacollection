// B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <assert.h>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{

	/*while(true)
	{
		int i=0;
		i++;
	}*/

	int numCase = 0;
	cin >> numCase;
	for (int i = 0; i < numCase; i++)
	{
		vector<double> vPi;
		long A,B;
		double result = 1;
		cin >> A >> B;
		
		for (int j = 0; j < A; j++)
		{
			double value;
			cin >> value;
			vPi.push_back(value);
		}

		double PressEnter = B+2;
		
		result = PressEnter;


		double MultiPi = 1;
		for(int k=0;k<A;k++)
		{
			MultiPi *=vPi[k]; 
		}

		double KeepTyping = 0;

		KeepTyping = ((double)(B-A+1))*(MultiPi) + ((double)(2*B+2-A))*(1-MultiPi);
		result = min(result,KeepTyping);
		
		for(int k=1;k<A;k++)
		{
			double MultiPi = 1;
			for(int t=0;t<A-k;t++)
			{
				MultiPi *=vPi[t];
			}
			double temp = ((double)(2*k+B-A+1))*(MultiPi) + ((double)(2*B+2+(2*k)-A))*(1-MultiPi);
			result = min(result,temp);
		}

		result = min(result,(double)(A+B+1));

		
		cout << "Case #" << (i+1) << ": " ;
		cout.precision(6);
		cout.setf(ios::fixed,ios::floatfield);
		cout << result << endl;
	}




	return 0;
}

