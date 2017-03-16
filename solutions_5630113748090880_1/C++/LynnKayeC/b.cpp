#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

void work(ifstream & fin, ofstream & fout, int caseno) {
    int n;
	fin >> n;
	unordered_map<int, int> counts;
	for (int i = 0; i < 2 * n - 1; ++i) {
		for (int j = 0; j < n; ++j) {
			int h;
			fin >> h;
			if (counts.find(h) == counts.end())
				counts[h] = 1;
			else
				++counts[h];
		}
	}
	vector<int> heights;
	for (auto it = counts.begin(); it != counts.end(); ++it) {
		if (it->second % 2 == 1)
			heights.push_back(it->first);
	}
	sort(heights.begin(), heights.end());
	fout << "Case #" << caseno << ":";
	for (auto h : heights)
		fout << " " << h;
	fout << endl;
}

int main() {
	ifstream fin;
	fin.open("input");
	ofstream fout;
	fout.open("output");
	int testcase;
	fin >> testcase;
	for (int i = 0; i < testcase; ++i) {
		work(fin, fout, i + 1);
	}
	fin.close();
	fout.close();
	return 0;
}
