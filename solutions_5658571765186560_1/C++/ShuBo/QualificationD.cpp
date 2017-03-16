// CodeJam.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <assert.h>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

bool solve(const int &X, const int &R, const int &C) {
	if (X == 1) return true;
	if (X >= 7) return false;

	if (R < X && C < X) return false;
	if (R % X != 0 && C % X != 0) return false;
	if (R < X - 1 || C < X - 1) return false;
	
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream infile("D-large.in");
	ofstream outfile("D-large.out");

	//ifstream infile("test.txt");
	//ofstream outfile("test.out");

	string line;
	int numCase;
	getline(infile, line);
	istringstream iss(line);
	iss >> numCase;
	cout << "numCase: " << numCase << endl;

	int curCase = 0;
	while (getline(infile, line)) {
		int X, R, C;
		stringstream ss2(line);
		ss2 >> X >> R >> C;
		printf("X: %d, R: %d, C: %d\n", X, R, C);

		bool ans = 0;
		ans = solve(X, R, C);
		outfile << "Case #" << ++curCase << ": " << (ans ? "GABRIEL" : "RICHARD") << endl;
	}
	assert(curCase == numCase);
	infile.close();
	outfile.close();

	system("pause");
	return 0;
}

