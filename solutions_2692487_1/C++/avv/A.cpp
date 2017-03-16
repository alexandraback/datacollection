// A.cpp : Defines the entry point for the console application.
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

map<pair<int, int>, int> dp;
int rec(vector<int>& data, int currentI, int a)
{
	pair<int, int> dpPair(currentI, a);
	if (dp.find(dpPair) != dp.end())
	{
		return dp.find(dpPair)->second;
	}
	int newCurrentI = -1;
	for (int i = currentI; i < data.size(); ++i)
	{
		if (data[i] < a)
		{
			a += data[i];
		}
		else
		{
			newCurrentI = i;
			break;
		}
	}

	if (newCurrentI == -1)
	{
		dp.insert(make_pair(dpPair, 0));
		return 0;
	}

	int result1 = rec(data, newCurrentI + 1, a) + 1;
	if (a - 1 != 0)
	{
		int result2 = 0;
		while (data[newCurrentI] >= a)
		{
			a += a - 1;
			result2++;
		}
		result2 = result2 + rec(data, newCurrentI, a);

		result1 = min(result1, result2);
	}
	
	dp.insert(make_pair(dpPair, result1));
	return result1;
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	ofstream fout("out.txt");
	ifstream fin("in.txt");
	int T;
	fin >> T;

	for (int t = 0; t < T; ++t )
	{
		dp.clear();
		
		int a, n;
		fin >> a >> n;
		vector<int> data(n);
		//dp.resize(n + 1, -1);
		for (int i = 0; i < n; ++i)
		{
			fin >> data[i];
		}
		sort(data.begin(), data.end());
		rec(data, 0, a);
		fout << "Case #" << t + 1 <<": " << dp.find(make_pair(0, a))->second << endl;
	}
	return 0;
}

