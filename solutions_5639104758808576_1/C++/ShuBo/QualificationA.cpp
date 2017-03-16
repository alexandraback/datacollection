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

using namespace std;

void solve(int numItem, int shyInt, int &ans) {
	int NUM = numItem + 1;
	int *shy = new int[NUM];
	while (numItem >= 0) {
		shy[numItem] = shyInt % 10;
		shyInt /= 10;
		numItem--;
	}

	int aud = 0, minAud = 0;
	for (int i = 0; i < NUM; ++i) {
		if (aud + shy[i] < ++minAud) {
			ans += (minAud - shy[i] - aud);
			aud += (minAud - shy[i] - aud);
		}
		else {
			aud += shy[i];
		}
	}
	delete[] shy;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream infile("A-large.in");
	ofstream outfile("A-large.out");

	string line;
	int numCase;
	getline(infile, line);
	istringstream iss(line);
	iss >> numCase;
	cout << "numCase: " << numCase << endl;

	int curCase = 0;
	while (getline(infile, line)) {
		int numItem, shyInt;
		stringstream ss2(line);
		ss2 >> numItem >> shyInt;
		cout << "numItem: " << numItem << endl;
		cout << "shyInt: " << shyInt << endl;

		int ans = 0;
		solve(numItem, shyInt, ans);
		outfile << "Case #" << ++curCase << ": " << ans << endl;
	}
	assert(curCase == numCase);
	infile.close();
	outfile.close();

	system("pause");
	return 0;
}

