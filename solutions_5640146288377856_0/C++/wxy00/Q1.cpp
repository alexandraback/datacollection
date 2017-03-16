// Q1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int find_floor(int C, int W)
{
	int temp;
	temp = int(floor(double(C) / double(W)));
	return temp;
}


int find_turns(int R, int C, int W)
{
	int res;

	int remain,addon;

	remain = C - find_floor(C, W)*W;

	if (remain > 0)
		addon = 1;
	else
		addon = 0;

	res = find_floor(C, W)*R+W-1+addon;

	return res;
}




int main()
{
    freopen("D://wxy_projects//A-small-attempt0.in", "r", stdin);
    freopen("D://wxy_projects//A-small-attempt0.out", "w", stdout);

	int Casenum;
	cin >> Casenum;

	for(int i=0; i<Casenum; i++) {
		int R,C,W;
		
		cin >> R>>C>>W;


		cout << "Case #" << (i+1) << ": " << find_turns(R,C,W)<<" "<<endl;
	}
	return 0;
}

