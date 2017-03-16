#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;


void solve(ifstream& fin, ofstream& fout) {
	int B;
	long long M;
	fin >> B >> M;
	vector<vector<int>> a(B, vector<int>(B));
	if (M > (1LL << (B - 2))) {
		fout << "IMPOSSIBLE" << endl;
		return;
	}
	fout << "POSSIBLE" << endl;
	a[0][B - 1] = 1;
	M -= 1;

	long long u = 1;
	for (int i = 1; i < B-1; i++) {
		if (M == 0) break;
		if (M >= u) {
			a[0][i] = a[i][B - 1] = 1;
			for (int j = 1; j < i; j++) {
				a[i][j] = 1;
			}
			M -= u;
		}
		else {
			M--;
			a[0][i] = a[i][B - 1] = 1;
			long long k = 1;
			for (int j = 1; j < i; j++) {
				if (M == 0) break;
				if (M & k) {
					a[i][j] = 1;
					M -= k;
				}
				k = k * 2;
			}
		}
		u = u * 2;
	}

	for (int i = 0; i < B; i++) {
		for (int j = 0; j < B; j++) {
			fout << a[i][j];
		}
		fout << endl;
	}
}

int main(int argc, char *argv[])
{
	const char* inn;
	if (argc < 2) {
		inn = "c.in";
	}
	else {
		inn = argv[1];
	}
	string in = inn;
	string out = in.replace(in.find(".in"), in.length(), ".out");
	ifstream fin(inn);
	ofstream fout(out);

	int t;
	fin >> t;

	for (int cs = 1; cs <= t; cs++) {
		fout << "Case #" << cs << ": ";
		solve(fin, fout);
	}
	fout.close();

	return 0;
}
