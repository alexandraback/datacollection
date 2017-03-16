#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <fstream>

using namespace std;

int T;
long long B, M;

int set[51][51];

long long two[51];

ifstream infile;
ofstream outfile;

void reset() {
	for (int i = 1; i <= 50; ++i)
		for (int j = 1; j <= 50; ++j)
			set[i][j] = 0;
}

void proc() {
	int cur = 1;
	long long cnt = 1;
	set[1][B] = 1;
	while (cnt < M) {
		++cur;
		set[1][cur] = 1;
		if (M - cnt >= two[cur - 2]) {
			cnt += two[cur - 2];
			for (int j = 2; j < cur; ++j)
				set[cur][j] = 1;
			set[cur][B] = 1;
		}
		else {
			long long tmp = M - cnt;
			int iter = cur;
			while (tmp > 1) {
				--iter;
				if (tmp > two[iter - 2]) {
					set[cur][iter] = 1;
					cnt += two[iter - 2];
					tmp -= two[iter - 2];
				}
			}
			if (tmp == 1) {
				set[cur][B] = 1;
				++cnt;
			}
		}
	}
}

int main() {
	infile.open("input.txt");
	outfile.open("output.txt");

	infile >> T;

	two[0] = 1;
	for (int i = 1; i <= 50; ++i)
		two[i] = two[i - 1] * 2;

	for (int p = 1; p <= T; ++p) {
		reset();

		infile >> B >> M;
		outfile << "Case #" << p << ": ";

		if (M > two[B - 2]) {
			outfile << "IMPOSSIBLE" << endl;
			continue;
		}

		outfile << "POSSIBLE" << endl;
		proc();
		for (int i = 1; i <= B; ++i) {
			for (int j = 1; j < B; ++j)
				outfile << set[i][j];
			outfile << set[i][B] << endl;
		}
	}

	infile.close();
	outfile.close();
	return 0;
}