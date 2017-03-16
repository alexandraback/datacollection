#include <fstream>

using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int T;
	in >> T;
	for (int test = 1; test <= T; test++) {
		int S_max, sum = 0, invite = 0;
		in >> S_max;
		for (int i = 0; i < S_max + 1; i++) {
			if (sum < i) {
				++sum, ++invite;
			}
			char S_i;
			in >> S_i;
			sum += S_i-'0';
		}

		out << "Case #" << test << ": " << invite << endl;
	}
	return 0;
}