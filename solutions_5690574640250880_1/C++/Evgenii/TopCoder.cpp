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

bool dp[2501][51];
vector<int> res;
bool solve(int qt, int count, int len) {
	if (dp[qt][count]) return false;
	if (qt == 0) return true;
	if (count == 0) return false;
	for (int i = 2; i <= len && i <= qt; ++i) {
		res.push_back(i);
		if (solve(qt - i, count - 1, len)) {
			return true;
		}
		res.pop_back();
	}
	dp[qt][count] = true;
	return false;
}

#ifdef GEN_LOCAL_TEST
bool bfsTest(vector<vector<char> > & test2, int r, int c, int m) {
	vector<vector<char> > test = test2;
	for (int i1 = 0; i1 < r; ++i1)
	for (int i2 = 0; i2 < c; ++i2) {
		if (test2[i1][i2] == '*') continue;
		test = test2;
		// bfs
		vector<int> x, y, x2, y2;
		x.push_back(i1);
		y.push_back(i2);
		int qt = 1;
		test[i1][i2] = '+';
		while (!x.empty()) {
			x2.clear();
			y2.clear();
			for (int k = 0; k < x.size(); ++k) {
				int xc = x[k];
				int yc = y[k];
				bool bStart = true;
				for (int j1 = -1; j1 < 2; ++j1) {
					for (int j2 = -1; j2 < 2; ++j2) {
						if (xc + j1 < 0 || yc + j2 < 0 || xc + j1 >= r || yc + j2 >= c) continue;
						if (test[xc + j1][yc + j2] == '*') {
							bStart = false;
							break;
						}
					}
					if (!bStart) break;
				}
				if (!bStart) continue;
				for (int j1 = -1; j1 < 2; ++j1) {
					for (int j2 = -1; j2 < 2; ++j2) {
						if (xc + j1 < 0 || yc + j2 < 0 || xc + j1 >= r || yc + j2 >= c) continue;
						if (test[xc + j1][yc + j2] == '.') {
							++qt;
							test[xc + j1][yc + j2] = '#';
						}
						if (j1 != 0 && j2 != 0) continue;
						if (test[xc + j1][yc + j2] != '+') {
							x2.push_back(xc + j1);
							y2.push_back(yc + j2);
							test[xc + j1][yc + j2] = '+';
						}
					}
				}
			}
			x.swap(x2);
			y.swap(y2);
		}
		if (qt != r*c - m) continue;
		test2 = test;
		for (int i = 0; i < test.size(); ++i)
			for (int j = 0; j < test[i].size(); ++j)
			if (test2[i][j] != '*')
				test2[i][j] = '.';
		test2[i1][i2] = 'c';
		return true;
	}
	return false;
}

bool testResult(vector<vector<char> > dt, bool bFailed, int r, int c, int m) {
	bool bTestFailed = false;
	if (!bFailed) {
		vector<vector<char> > test(r, vector<char>(c, '.'));
		for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			test[i][j] = dt[i][j];
		if (!bfsTest(test, r, c, m)) {
			ofs << "--------------" << endl;
			ofs << r << " " << c << " " << m << endl;
			printRes(test, r, c);
			return false;
		}
	}
	else {
		int maxVal = 1 << r*c;
		vector<vector<char> > test(r, vector<char>(c, '.'));
		for (int i = 0; i < maxVal; ++i) {
			int mqt = 0;
			for (int j = 0; j < r*c; ++j) {
				if (i & (1 << j)) {
					test[j / c][j % c] = '*';
					++mqt;
				}
				else
					test[j / c][j % c] = '.';
			}
			if (mqt != m) continue;
			if (bfsTest(test, r, c, m)) {
				ofs << r << " " << c << " " << m << endl;
				ofs << "--------------" << endl;
				printRes(test, r, c);
				return false;
			}
		}
	}
	return true;
}
#endif

int main(int argc, char* argv[])
{

	ifstream ifs("test.txt", ifstream::in);

	int t;
	ifs >> t;

	int r, c, m;
	for (int idx = 0; idx < t; ++idx) {
		ofs << "Case #" << idx + 1 << ":" << endl;
		vector<vector<char> > dt(51, vector<char>(51, '*'));
		ifs >> r >> c >> m;
		int mval = r*c - m;
		bool bFailed = true;
		if (r == 1 || c == 1) {
			if (r == 1)
				for (int i = 0; i < mval; ++i) dt[0][i] = '.';
			else
				for (int i = 0; i < mval; ++i) dt[i][0] = '.';
			dt[0][0] = 'c';
			printRes(dt, r, c);
			bFailed = false;
		}
		else if (mval == 1) {
			dt[0][0] = 'c';
			printRes(dt, r, c);
			bFailed = false;
		}
		else {
			int tmp = min(c, mval / 2);
			for (int i = 2; i <= tmp; ++i) {
				res.clear();
				memset(dp, 0, sizeof(dp));
				if (solve(mval - 2 * i, r - 2, i)) {
					res.push_back(i);
					res.push_back(i);
					sort(res.rbegin(), res.rend());
					for (int j = 0; j < res.size(); ++j)
					for (int k = 0; k < res[j]; ++k)
						dt[j][k] = '.';
					dt[0][0] = 'c';
					printRes(dt, r, c);
					bFailed = false;
					break;
				}
			}
			if (bFailed) {
				ofs << "Impossible" << endl;
			}
		}

#ifdef GEN_LOCAL_TEST
		// testing result;
		if (!testResult(dt, bFailed, r, c, m))
			break;
#endif
	}

	return 0;
}

