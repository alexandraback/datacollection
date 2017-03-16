// Q3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

static long int M[130];

int ini_M()
{
	int i;
	for (i = 1; i < 130; i++)
		M[i] = 0;

	return 0;
}



int check_pay(int N, int C, int D)
{
	int i,flag;
	long int number, remain;

	remain = N;
	for (i = 0; i < D; i++)
	{
		number = long int(floor(double(N) / double(M[D - 1 - i])));
		if (number>C)
			remain = remain - C*M[D - 1 - i];
		else
			remain = remain - number*M[D - 1 - i];
	}

	if (remain > 0)
		flag = 1;
	else
		flag = 0;

	return flag;
}


long int check_range(int C, int D)
{
	int i;
	long int range;
	if (M[0] > 1)
		return 0;

	for (i = 0; i < D; i++)
	{
		if (i == 0)
			range = C*M[0];
		else
		{
			if (M[i]>(range + 1))
				return range;
			else
				range = range + C*M[i];
		}
	}

	return range;

}

int resort_M(int D, long int addon)
{
	int i,new_loc;
	for (i = 0; i < D; i++)
	{
		if (addon < M[i])
			break;
	}

	new_loc = i;

	for (i = D; i > new_loc; i--)
		M[i] = M[i - 1];
	M[new_loc] = addon;

	return 0;
}


long int cal_addon(int C, int D, long int V)
{
	int i;
	long int range,addon;

	range = check_range(C, D);

	if (range < V)
		addon = range + 1;
	else
		addon = 0;

	return addon;
}

int check_addon_number(int C, int D, int V)
{
	int i,ori;
	long int range,addon;

	ori = D;
	range = check_range(C, D);

	while (range < V)
	{
		addon = cal_addon(C, D, V);
		resort_M(D, addon);
		D++;
		range = check_range(C, D);
	}

	return D - ori;

}



int main()
{
    freopen("D://wxy_projects//C-small-attempt0.in", "r", stdin);
    freopen("D://wxy_projects//C-small-attempt0.out", "w", stdout);

	int i;
	int Casenum;
	cin >> Casenum;

	

	for(i=0; i<Casenum; i++) {
		int C,D;
		long int V;
		int j;
		ini_M();

		cin >> C >> D >> V;

		for (j = 0; j < D; j++)
		{
			cin >> M[j];
		}

		cout << "Case #" << (i+1) << ": " << check_addon_number(C,D,V) << endl;
	}
	return 0;
}

