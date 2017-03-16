#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;


ifstream infile;
ofstream outfile;

string s;

int T;

int N;

int tmp;

int b[2501];

void reset() {
	for (int i = 1; i <= 2500; ++i)
		b[i] = 0;
}

int main() {
	infile.open("input.txt");
	outfile.open("output.txt");

	infile >> T;

	for (int p = 1; p <= T; ++p) {
		reset();

		outfile << "Case #" << p << ":";

		infile >> N;
		for (int i = 1; i <= N * (2 * N - 1); ++i) {
			infile >> tmp;
			++b[tmp];
		}

		for (int i = 1; i <= 2500; ++i) {
			if (b[i] % 2 != 0) {
				outfile << " " << i;
			}
		}
		
		outfile << endl;
	}

	infile.close();
	outfile.close();
	return 0;
}