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

int x, y;
//int currX, currY;
string dir;
bool found = false; 


int _tmain(int argc, _TCHAR* argv[])
{
	ofstream fout("out.txt");
	ifstream fin("in.txt");
	int T;
	fin >> T;
	string str;
	

	for (int t = 0; t < T; ++t )
	{
		int64 n;
		
		fin >> x >> y;
		//vector<vector<int>> data(202, vector<int>(202, -1));
		//vector<vector<pair<int, int>>> from(202, vector<pair<int, int>>(202, make_pair(-1, -1)));

		//vector<pair<int, int>> front;
		//front.push_back(make_pair(0, 0));
		//data[0 + 101][0 + 101] = 0;
		//from[0 + 101][0 + 101] =  make_pair(0, 0);
		//dir.clear();
		//rec(front, 1);

		//int currX = 0;
		//int currY = 0;
		int step = 1;
		dir.clear();
		
		if (x > 0)
		for (int currX = 0; currX < x; ++currX)
		{
			dir.push_back('W');
			dir.push_back('E');
		}
		if (x < 0)
		for (int currX = 0; currX < abs(x); ++currX)
		{
			dir.push_back('E');
			dir.push_back('W');
		}


		
		if (y > 0)
		for (int currY = 0; currY < y; ++currY)
		{
			dir.push_back('S');
			dir.push_back('N');
		}
		if (y < 0)
		for (int currY = 0; currY < abs(y); ++currY)
		{
			dir.push_back('N');
			dir.push_back('S');
		}

		//reverse(dir.begin(), dir.end());
		
		fout << "Case #" << t + 1 <<": " << dir << endl;
	}
}

