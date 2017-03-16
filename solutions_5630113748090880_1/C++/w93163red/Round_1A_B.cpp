// Round_1A_B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
	int t;
	int nn;
	ifstream ifile;
	ifile.open("B-large.in");
	ofstream ofile;
	ofile.open("ans.txt");
	ifile >> t;
	
	for (int n = 1; n <= t; n++)
	{	
		unordered_map<int, int> map;
		vector<int> num;
		ifile >> nn;
		for (int i = 0; i < (2 * nn - 1)*nn; i++)
		{
			int a;
			ifile >> a;
			if (map.find(a) == map.end())
			{
				map[a] = 1;
			}
			else
			{
				map[a] = map[a] + 1;
			}
		}
		for (unordered_map<int, int>::iterator it=map.begin(); it != map.end(); it++)
		{
			int a = it->second;
			if (a % 2)
			{
				num.push_back(it->first);
			}
		}

		sort(num.begin(), num.end());
		ofile << "Case #" << n << ":";
		for (int i = 0; i < num.size(); i++)
		{
			ofile << " " << num[i];
		}
		ofile << endl;
	}
	
    return 0;
}

