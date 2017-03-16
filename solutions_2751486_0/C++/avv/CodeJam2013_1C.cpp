// CodeJam2013_1C.cpp : Defines the entry point for the console application.
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
#include "map"
using namespace std;

#define int64 long long
#define F(vec, index) for (int index = 0; index  < vec.size(); ++index)
int _tmain(int argc, _TCHAR* argv[])
{
	ofstream fout("out.txt");
	ifstream fin("in.txt");
	int T;
	fin >> T;
	string str;
	vector<bool> data;
	for (int t = 0; t < T; ++t )
	{
		int n;
		fin >> str;
		fin >> n;

		data.clear();
		data.resize(str.length(), false);

		F(data, i)
		{
			if (str[i] == 'a' || 
				str[i] == 'e' || 
				str[i] == 'i' || 
				str[i] == 'o' ||
				str[i] == 'u')
			{
				data[i] = true;
			}
		}
		int currN = 0;
		int begin = 0;
		int result = 0;
		F(data, i)
		{
			if (data[i])
			{
				currN = 0;
			}

			if (!data[i])
			{
				currN++;
			}
			if (currN == n)
			{
				currN--;
				int formula = ((i - n - begin + 1) + 1) * ((data.size() - i - 1) + 1);
				result += formula;
				begin = i - n + 2;

			}
		}
		
		fout << "Case #" << t + 1 <<": " << result << endl;
	}
}

