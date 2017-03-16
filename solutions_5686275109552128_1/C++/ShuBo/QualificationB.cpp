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

int solve(const vector<int> &q) {
	int MAX = INT_MIN;
	for (int i = 0; i < q.size(); ++i) {
		MAX = max(MAX, q[i]);
	}

	int ans = MAX;
	for (int eat = 2; eat < MAX; ++eat) {
		int steps = 0;
		for (int i = 0; i < q.size(); ++i) {
			int pan = q[i];
			while (pan > eat) {
				pan -= eat;
				++steps;
			}
		}

		ans = min(ans, eat + steps);
	}

	return ans;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream infile("B-large.in");
	ofstream outfile("B-large.out");

	string line;
	int numCase;
	getline(infile, line);
	istringstream iss(line);
	iss >> numCase;
	cout << "numCase: " << numCase << endl;

	int curCase = 0;
	while (getline(infile, line)) {
		int numItem;
		stringstream ss2(line);
		ss2 >> numItem;
		//cout << "numItem: " << numItem << endl;

		vector<int> ps;
		getline(infile, line);
		stringstream ss3(line);
		for (int i = 0; i < numItem; ++i) {
			int p;
			ss3 >> p;
			ps.push_back(p);
		}
		assert(ps.size() == numItem);

		int ans = 0;
		ans = solve(ps);
		outfile << "Case #" << ++curCase << ": " << ans << endl;
		//system("pause");
	}
	assert(curCase == numCase);
	infile.close();
	outfile.close();

	system("pause");
	return 0;
}

