//============================================================================
// Name        : Problem.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	// open a file in read mode.
	ifstream infile;
//	infile.open("src/in");
//	infile.open("src/D-small-attempt0.in");
	infile.open("src/D-large.in");

	// open a file in write mode.
	ofstream outfile;
	outfile.open("src/out");

	long long T;
	infile>>T;
	for (long long i = 1; i <= T; ++i)
	{
		long long K, C, S;
		infile>>K>>C>>S;

		outfile<<"Case #"<<i<<":";

		if (C * S < K)
			outfile<<" IMPOSSIBLE";
		else
		{
			long long t = K / C;
			long long v=1;
			for (long long j = 0; j < t; ++j)
			{
				//each covers j*k+1 -- (j+1)*k
				long long a = 1;
				for (v = j*C+1; v <= (j+1)*C; ++v)
				{
					a = (a-1)*K + v;
				}
				outfile<<" "<<a;
			}
			if (K%C)
			{
				long long a = 1;
                for (long long h = 0; h < C; ++h)
                {
                	a = (a-1)*K + v;
                	if(v<K)
                		++v;
                }
                outfile<<" "<<a;
			}
		}
		outfile<<endl;
	}
	return 0;
}
