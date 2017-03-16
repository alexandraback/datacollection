#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ifstream input;
	ofstream output;
	input.open("./Downloads/C-small-attempt1.in");
	output.open("result2016c3s");

	unsigned T;
	input >> T;

	for (unsigned t = 0; t < T; t ++) {
		unsigned J, P, S, K;
		input >> J;
		input >> P;
		input >> S;
		input >> K;

		unsigned total = J * P * S;
		unsigned result = total;
		unsigned sub = J * P * K;

		if (total > sub) {
			result = sub;
		}

		output << "Case #" << t + 1 << ": " << result << endl;
		if (result == total) {
			for (unsigned j = 0; j < J; j ++) {
				for (unsigned p = 0; p < P; p ++) {
					for (unsigned s = 0; s < S; s ++) {
						output << j + 1 << " " << p + 1 << " " << s + 1 << endl;
					}
				}
			}
		} else {
			for (unsigned j = 0; j < J; j ++) {
				for (unsigned p = 0; p < P; p ++) {
					for (unsigned k = 0; k < K; k ++) {
                                                output << j + 1 << " " << p + 1 << " " << ((p + k) % S) + 1 << endl;
                                        }
                                }
                        }
		}
	}
	return 0;
}
