
#ifdef VC_SOLUTION_USED
#include "A.h"
#endif

#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <string>

using namespace std;

void A()
{
	int T = 0;
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		long long int P=0, Q=0;
		bool handleP = true;
		string input;
		cin >> input;

		for(int i=0; i<input.length(); ++i)
		{
			if(input[i] == '/')
			{
				handleP = false;
			}
			else
			{
				if(handleP)
				{
					P = P*10 + input[i] - '0';
				}
				else
				{
					Q = Q*10 + input[i] - '0';
				}
			}
		}

		int time=1;
		int first=-1;
		for(;;)
		{
			P*=2;
			if(P>=Q)
			{
				if(first==-1)
				{
					first = time;
				}
				P -= Q;
			}

			if(time > 40 || P == 0)
				break;
			++time;
		}

		if(time > 40)
			cout << "Case #" << t << ": impossible" << endl;
		else
			cout << "Case #" << t << ": " << first << endl;
	}
}

#ifndef VC_SOLUTION_USED
int main()
{
	A();
	return 0;
}
#endif