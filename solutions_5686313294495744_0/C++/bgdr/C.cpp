#include <cstdlib>
#include <map>
#include "assert.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <bitset>
using namespace std;
int N, J;
int numSol = 0;

vector<uint> DIVS = {11, 3, 5};

vector<uint> jam(bitset<32> x) {
	vector<uint> divs;
	if (!x[0] || !x[N - 1]) {
		return divs;
	}
	for (uint b = 2; b <= 10; ++b) {
		for (auto & DIV : DIVS) {
			uint ret = 0;
			uint bb = 1;
			for (int i = 0; i < N; ++i) {
				ret = (ret + bb * x[i]) % DIV;
				bb = (b * bb) % DIV;
			}
			if (ret == 0) {
				divs.push_back(DIV);
				break;
			}
		}
	}
	return divs;
}

bool foundsol() {
	numSol++;
	if (numSol == J) {
		return false;
	}
	return true;
}

void rec(uint from, uint to, vector<bitset<32> > & res) {
	for (int i = from; i <= to; ++i) {
		bitset<32> x(i);
		auto divs = jam(x);
		if (divs.size() == 9) {
			res.push_back(x);
			if (!foundsol()) {
				break;
			}
		}
	}
}

bool verify(bitset<32> x, uint div, uint b) {
	if (!x[0] || !x[N - 1]) {
		return false;
	}
	uint ret = 0;
	uint bb = 1;
	for (int i = 0; i < N; ++i) {
		ret = (ret + bb * x[i]) % div;
		bb = (b * bb) % div;
	}
	return ret == 0;
}

int main(int argc, char** argv) {
	ofstream fout("C-small.out");
	ifstream fin("/home/bgd/Downloads/C-small-attempt0.in");
	fin.exceptions(ifstream::failbit | ifstream::badbit);
	ostream & out = fout;
	int T, N;
	fin >> T;
	for (int t = 1; t <= T; ++t) {
		vector<pair<string, string>> vs;
	
		fin >> N;
		int ret = 0;
		for(int i = 0; i < N; ++i) {
			pair<string, string> ps;
			fin >> ps.first >> ps.second;
			vs.push_back(ps);
		}
		for (int mk = 0; mk < (1 << N); ++mk) {
			int cret = 0;
			map<string, bool> seen1;
			map<string, bool> seen2;
			for( int i = 0; i < N; ++i) {
				if (mk & (1 << i)) {
					seen1[vs[i].first] = true;
					seen2[vs[i].second] = true;
				}
			}
			for( int i = 0; i < N; ++i) {
				if (!(mk & (1 << i))) {
					if (seen1[vs[i].first] && seen2[vs[i].second]) {
						cret++;
					}
				}
			}
			if (cret > ret) {
				ret = cret;
			}
		}
		out << "Case #" << t << ": " << ret << endl;
	}
	return 0;
}

