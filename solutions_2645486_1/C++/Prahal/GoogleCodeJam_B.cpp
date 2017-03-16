// GoogleCodeJam_B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>

#define MAX_N 10000

using namespace std;

ifstream fin("C:\\Users\\rmallela\\Desktop\\Input.in");
ofstream fout("C:\\Users\\rmallela\\Desktop\\Output.txt");

int T, N, R, E, values[MAX_N], maxvalue, sums[MAX_N + 3];

int main()
{
	fin >> T;
	for(int i = 0; i < T; i++)
	{
		fin >> E >> R >> N; for(int j = 0; j < N; j++) fin >> values[j];
		memset(sums, 0, sizeof(sums));
		for(int j = N - 1; j > -1; j--) sums[j] = sums[j + 1] + values[j];
		int currE = E;		maxvalue = 0;
		for(int j = 0; j < N; j++)
		{
			if(values[j] > sums[j] - values[j]) {maxvalue += currE*values[j]; currE = R;}
			else if(values[j] < sums[j] - values[j] && E - currE >= R) {currE = E;}
			else {maxvalue += R*values[j];}
		}
		fout << "Case #" << i + 1 << ": " << maxvalue << "\n";
	}
	return 0;
}