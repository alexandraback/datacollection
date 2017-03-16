#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream inf("C-small-attempt0.in");
ofstream ouf("output.txt");

vector <int> d;
bool ok[35];
int C, D, V;

int check() {
	fill(ok, ok + 35, false);
	for (int mask = 0; mask < (1 << d.size()); ++mask) {
		int sum = 0;
		for (int j = 0; j < d.size(); ++j) {
			if (mask & (1 << j)) {
				sum += d[j];
			}
		}
		if (sum <= V) {
			ok[sum] = true;
		}
	}
	for (int i = 0; i <= V; ++i) {
		if (!ok[i]) return i;
	}
	return -1;
}


int main() {
	int T; inf >> T;
	for (int t = 1; t <= T; ++t) {
		cerr << t << endl;
		inf >> C >> D >> V;
		if (C != 1) continue;
		d.clear();
		for (int i = 0; i < D; ++i) {
			int den;
			inf >> den;
			d.push_back(den);
		}
		int q = check();
		while (q != -1) {
			d.push_back(q);
			q = check();
		}
		ouf << "Case #" << t << ": " << d.size() - D << endl;
	}
}