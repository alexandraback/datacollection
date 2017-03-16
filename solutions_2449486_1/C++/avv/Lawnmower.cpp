// Lawnmower.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include "vector"
#include "string"
#include "set"
#include "sstream"
#include "algorithm"
#include "cmath"
#include "cassert"
#include "iostream"
#include <fstream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	ofstream fout("out.txt");
	ifstream fin("in.txt");
	int T;
	fin >> T;
	vector<int> vec;
	vector<int> maxI;
	vector<int> maxJ;
	for (int t = 0; t < T; ++t)
	{
		int n, m;
		fin >> n >> m;
		vec.clear();
		vec.resize(n * m, 0);
		for (int i = 0; i < n * m; ++i)
		{
			fin >> vec[i];
		}
		maxI.clear();
		maxI.resize(n, 0);
		maxJ.clear();
		maxJ.resize(m, 0);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				maxI[i] = max(maxI[i], vec[i * m + j]);
				maxJ[j] = max(maxJ[j], vec[i * m + j]);
			}
		}
		bool possible = true;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				assert(vec[i * m + j] <= maxI[i]);
				assert(vec[i * m + j] <= maxJ[j]);
				if (vec[i * m + j] != maxI[i] && vec[i * m + j] != maxJ[j])
				{
					possible = false;
				}
			
			}
		}
		if (possible)
		{
			fout << "Case #" << t + 1 << ": YES" << endl;
		}
		else
		{
			fout << "Case #" << t + 1 << ": NO" << endl;
		}
	}
	return 0;
}

