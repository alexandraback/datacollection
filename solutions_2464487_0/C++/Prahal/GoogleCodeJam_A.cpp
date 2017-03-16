// GoogleCodeJam_A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>

using namespace std;

ifstream fin("C:\\Users\\rmallela\\Desktop\\Input.in");
ofstream fout("C:\\Users\\rmallela\\Desktop\\Output.txt");

int T;

int main()
{
	fin >> T;
	for(int i = 0; i < T; i++)
	{
		int r, t;
		fin >> r >> t;
		int n = 1;
		while(true)
		{
			long E = (n - 1);
			double area = n*(2*r + 1) + 2*(E*(E + 1));
			if(area <= t) n++;
			else break;
		}
		fout << "Case #" << i + 1 << ": " << --n << "\n";
	}
	return 0;
}