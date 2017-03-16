#include <cstdlib>
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
	ofstream fout("C.large.out");
	ostream & out = fout;
	N = 32;
	J = 500;
	vector<bitset<32> > res;
	rec(0, (1LL << N) - 1, res);
	out << "Case #1:" << endl;

	for (auto & x : res) {
		bool bad = false;
		auto divs = jam(x);
		for (int b = 2; b <= 10; ++b) {
			if (!verify(x, divs[b - 2], b)) {
				bad = true;
			}
		}
		if (N == 16) {
			out << (bitset<16>(x.to_ulong())) << " ";
		} else {
			out << x << " ";
		}
		for (int i = 0; i < 9; ++i) {
			out << divs[i] << " ";
		}
		if (bad) {
			out << "   BAD";
		}
		out << endl;
	}

//	cout << res.size() << endl;
	return 0;
}

