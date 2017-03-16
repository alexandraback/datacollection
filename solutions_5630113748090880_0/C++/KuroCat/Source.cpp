#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;


int main() {
	ifstream in("B-small-attempt0.in");
	ofstream out("smalloutput.txt");
	int caseNum;
	in >> caseNum;
	for (int i = 1; i <= caseNum; ++i) {
		int n;
		in >> n;
		vector<vector<int>> paper(2 * n - 1, vector<int>(n, 0));
		for (int j = 0; j < 2 * n - 1; ++j) {
			for (int m = 0; m < n; ++m) {
				in >> paper[j][m];
			}
		}

		int count[2501];
		for (int j = 0; j < 2501; ++j) {
			count[j] = 0;
		}
		
		for (auto p : paper) {
			for (auto q : p) {
				count[q]++;
			}
		}

		vector<int> res;
		for (int j = 0; j < 2501; ++j) {
			if (count[j] % 2 == 1) {
				res.push_back(j);
			}
		}

		sort(res.begin(), res.end());
		out << "Case #" << i << ": ";
		for (auto p : res) {
			out << p << " ";
		}
		out << endl;
	}
	return 0;
}