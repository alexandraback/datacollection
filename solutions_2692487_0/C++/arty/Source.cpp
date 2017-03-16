#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("A-small-attempt1.in");
ofstream fout("A-small-attempt1.out");

int A, N;
vector<int> sizes;

int solve() {

	if (A == 1) return N;

	sort(sizes.begin(), sizes.end());

	int x = A;
	int result = 0;

	vector<int> costs;
	for (int i=0;i<sizes.size();i++) {
		costs.push_back(0);
		while (x <= sizes[i]) {
			costs[i] += 1;
			x += (x-1);
		}
		x += sizes[i];
	}

	result = costs.size();
	int tmp = 0;
	for (int i=0;i<costs.size();i++) {
		if (result > tmp + (costs.size() - i))
			result = tmp + (costs.size() - i);
		tmp += costs[i];
	}

	if (tmp < result) result = tmp;

	return result;

}


int main() {

	int T;
	fin >> T;

	for (int t=1;t<=T;t++) {
		
		sizes.clear();

		fin >> A >> N;

		for (int i=0;i<N;i++) {
			int tmp;
			fin >> tmp;
			sizes.push_back(tmp);
		}

		fout << "Case #" << t << ": " << solve() << "\n";
	}

	return 0;
}