// gcj_2a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>

using namespace std;

int Solve(int R, int  C, int W)
{
	int result = 0;
	if (C % W == 0)
	{
		result = R*(C / W) + (W-1);
	}
	else
	{
		result = R*(C / W) + W;
	}
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream input = ifstream("input.txt");
	ofstream output = ofstream("output.txt");
	int T = 0;
	input >> T;
	for (int counter = 0; counter < T; ++counter)
	{
		int R = 0, C = 0, W = 0;
		input >> R;
		input >> C;
		input >> W;		
		output << "Case #" << counter+1 << ": " << Solve(R, C, W) << "\r\n";
	}
	output.flush();
	output.close();
	input.close();
	return 0;
}

