// GoogleCodeJam_B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>

#define MAX_N 10

using namespace std;

ifstream fin("C:\\Users\\rmallela\\Desktop\\Input.in");
ofstream fout("C:\\Users\\rmallela\\Desktop\\Output.txt");

int T, N, R, E, values[MAX_N], maxvalue;

void solvemax(int curri, int gain, int currE)
{
	if(curri >= N) {maxvalue = max(gain, maxvalue); return;}
	if(currE > E) currE = E;
	if(currE < 0) currE = 0;
	for(int i = 0; i <= currE; i++) solvemax(curri + 1, gain + i*values[curri], currE - i + R);
}

int main()
{
	fin >> T;
	for(int i = 0; i < T; i++)
	{
		fin >> E >> R >> N; for(int j = 0; j < N; j++) fin >> values[j];
		maxvalue = 0;
		solvemax(0, 0, E);
		fout << "Case #" << i + 1 << ": " << maxvalue << "\n";
	}
	return 0;
}