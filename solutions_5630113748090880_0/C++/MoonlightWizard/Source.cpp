#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <list>
using namespace std;

int main() {
	fstream input, output;
	input.open("input.txt", ios::in);
	output.open("output.txt", ios::out);
	int t;
	input >> t;
	for (int i = 0; i < t; i++) {
		int n;
		input >> n;
		vector<int> allNums;
		for (int j = 0; j < (2 * n - 1)*n; j++) {
			int r;
			input >> r;
			allNums.push_back(r);
		}
		//cout << "currently have " << allNums.size() << " numbers" << endl;
		vector<int> left;
		for (int k = 0; k < allNums.size(); k++) {
			if (count(left.begin(), left.end(), allNums[k]) == 0 && count(allNums.begin(), allNums.end(), allNums[k]) % 2 == 1) {
				left.push_back(allNums[k]);
			}
		}
		cout << "left.size() is " << left.size() << endl;
		sort(left.begin(), left.end());
		output << "Case #" << i + 1 << ": ";
		for (int j = 0; j < left.size(); j++) {
			output << left[j] << " ";
		}
		output << endl;
	}
}