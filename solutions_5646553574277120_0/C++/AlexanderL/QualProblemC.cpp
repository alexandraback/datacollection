// QualProblemC.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{

//	freopen("C-test.in", "r", stdin);
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-smal.out", "w", stdout);
	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test)
	{
		int C, D, V;
		cin >> C >> D >> V;
		int val[10];
		for (int i = 0; i < D; ++i)
			cin >> val[i];
		int b[101] = { 0 };
		for (int m = 1; m < (1 << D); ++m)
		{
			int sum = 0;
			for (int j = 0; j < D; ++j)
				if (m & (1 << j))
					sum += val[j];
			if (sum <= V)
				b[sum] = 1;
		}

		int newval[35];
		int res = 0;
		for (int i = 1; i <= V; ++i)
		{
			if (b[i] == 0)
			{
				newval[res] = i;
				res++;
			}
			for (int m = 1; m < (1 << res); ++m)
			{
				int sum = 0;
				for (int j = 0; j < res; ++j)
					if (m & (1 << j))
						sum += newval[j];
				if (sum <= V)
					b[sum] = 1;
				else
					break;
			}
		}
		cout << "Case #" << test << ": " << res << endl;
	}
	return 0;
}

