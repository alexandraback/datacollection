#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

//#define GEN_LOCAL_TEST

ofstream ofs("ans.txt", ifstream::out);

void printRes(const vector<vector<char> > & dt, int r, int c) {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			ofs << dt[i][j];
		}
		ofs << endl;
	}
}

int main(int argc, char* argv[])
{

	ifstream ifs("test.txt", ifstream::in);

	int t;
	ifs >> t;

	int n;
	vector<double> v1, v2;
	double val;
	for (int idx = 0; idx < t; ++idx) {
		v1.clear();
		v2.clear();
		ifs >> n;
		for (int i = 0; i < n; ++i) {
			ifs >> val;
			v1.push_back(val);
		}
		for (int i = 0; i < n; ++i) {
			ifs >> val;
			v2.push_back(val);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());

		int i1 = 0;
		int i2 = 0;
		int sc1 = 0;
		while (i1 < v1.size()) {
			if (v1[i1] < v2[i2]) {
				++i1;
			}
			else {
				++sc1;
				++i1;
				++i2;
			}
		}

		int sc2 = 0;
		vector<bool> used(v1.size(), false);
		for (int i = 0; i < v1.size(); ++i) {
			int i1 = 0;
			while (i1 < v1.size() - 1 && used[i1]) ++i1;
			int i2 = i1;
			while (i2 < v1.size() - 1 && (used[i2] || v1[i] > v2[i2])) ++i2;
			if (used[i2] || v1[i] > v2[i2]) {
				used[i1] = true;
				++sc2;
			}
			else {
				used[i2] = true;
			}
		}
		ofs << "Case #" << idx + 1 << ": " << sc1 << " " << sc2 << endl;
	}

	return 0;
}

