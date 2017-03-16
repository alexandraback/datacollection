#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ifstream input;
	ofstream output;
	input.open("./Downloads/B-large.in");
	output.open("result2016c2l");

	unsigned T;
	input >> T;

	for (unsigned t = 0; t < T; t ++) {
		unsigned B;
		unsigned long long M;
		input >> B;
		input >> M;

		vector<unsigned> row(B, 0);
		vector<vector<unsigned> > map(B, row);
		bool result = true;

		if ((1ull << (B - 2)) < M) {
			result = false;
		} else {
			for (unsigned i = 0; i < B - 1; i ++) {
				for (unsigned j = 0; j < B - 1; j ++ ) {
					if (j > i) {
						map[i][j] = 1;
					}
				}
			}
			if ((1ull << (B - 2)) == M) {
                                map[0][B - 1] = 1;
				M --;
                        }
			for (unsigned i = 1; i < B - 1; i ++) {
				if (((M >> (i - 1)) % 2) == 1) {
					map[i][B - 1] = 1;
				}
			}
		}

		if (result) {
			output << "Case #" << t + 1 << ": POSSIBLE" << endl;
			for (unsigned i = 0; i < B; i ++) {
				for (unsigned j = 0; j < B; j ++) {
					output << map[i][j];
				}
				output << endl;
			}
		} else {
			output << "Case #" << t + 1 << ": IMPOSSIBLE" << endl;
		}
	}
	return 0;
}
