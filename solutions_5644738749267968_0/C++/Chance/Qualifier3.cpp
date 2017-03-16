#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

void solve(vector<vector<double> > blocks, int caseNum) {
	//vector<vector<double >> blocksCopy = blocks;
	int deceiptPoints = 0;
	size_t sz = blocks[0].size();
	size_t lowest_ind1 = 0;
	size_t highest_ind1 = sz - 1;
	size_t lowest_ind2 = 0;
	size_t highest_ind2 = sz - 1;
	for (size_t i = 0; i < sz; ++i) {
		double t = blocks[0][i];
		double t2 = blocks[1][sz - i - 1];
		if (blocks[0][highest_ind1] > blocks[1][highest_ind2]) {
			++deceiptPoints;
			highest_ind1--;
			highest_ind2--;
		}
		else {
			lowest_ind1++;
			highest_ind2--;
		}
	}
	int normPoints = 0;
	for (int i = (int)(sz-1); i >= 0; --i) {
		vector<double>::iterator it = lower_bound(blocks[1].begin(), blocks[1].end(), blocks[0][i]);
		if (it == blocks[1].end()) {
			normPoints++;
			blocks[1].erase(blocks[1].begin());
		}
		else {
			blocks[1].erase(it);
		}
	}
	cout << "Case #" << caseNum << ": " << deceiptPoints << " " << normPoints << endl;
}

int main(void){
	int numCases;
	cin >> numCases;
	for (int ii = 0; ii < numCases; ++ii) {
		size_t numBlocks;
		cin >> numBlocks;
		vector<vector<double> > blocks(2);
		for (size_t i = 0; i < 2; ++i) {
			blocks[i].resize(numBlocks);
			for (size_t j = 0; j < numBlocks; ++j) {
				cin >> blocks[i][j];
			}
			sort(blocks[i].begin(), blocks[i].end());
		}
		solve(blocks, ii + 1);
	}
	return 0;
}