#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <fstream>

using namespace std;

vector<string> dict;
int dp[4010][6];
string S;

int test (int p, int last) {
	if (p == S.length())
		return 0;
	if (dp[p][last] >=0)
		return dp[p][last];

	int minchange = -1;
	for (int i=0; i<dict.size(); i++) {
		if (dict[i].length() > S.length() - p)
			continue;
		int tmplast = p - last;
		int count = 0;
		bool valid = true;
		for (int j=0; j<dict[i].length(); j++) {
			if (dict[i][j] != S[p+j]) {
				if (p+j - tmplast < 5) {
					valid = false;
					break;
				}
				count++;
				tmplast = j;
			}
		}

		if (valid) {
			int newlast = p + dict[i].length() - tmplast;
			if (newlast > 5)
				newlast = 5;
			int tmp = test (p + dict[i].length(), newlast);
			if (tmp >=0 && (minchange==-1 || minchange > tmp + count))
				minchange = tmp + count;
		}
	}

	dp[p][last] = minchange;
	return minchange;
}

int main () {
	ifstream fin;
	fin.open ("dict.txt");
	char buff[8192];
	while (fin.getline (buff, 8192)) {
		dict.push_back (buff);
	}
	int testcases;

	cin >> testcases;

	for (int testcase=1; testcase<=testcases; testcase++) {
		cout << "Case #" << testcase << ": ";
		cerr << "Case " << testcase << endl;
	
		cin >> S;
		for (int k=0; k<=5; k++) {
		for (int i=0; i<S.length(); i++)
			dp[i][k] = -1;
			}
		cout << test(0, 5);

		cout << endl;
	}

	return 0;
}
