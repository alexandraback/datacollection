#include <fstream>

using namespace std;

long long getNum(int start, int c, int base);

int main() {
	//set input/output stream
	ifstream input;
	ofstream output;
	input.open("input.txt");
	output.open("output.txt");

	int T, k, c, s;
	input >> T;
	for(int i = 1; i <= T; i++) {
		input >> k >> c >> s;
		output << "Case #" << i << ": ";
		if(c * s < k) {
			output << "IMPOSSIBLE" << endl;
		}else {
			for(int i = 0; i < s; i++) {
				if(i *c + 1 <= k) {
					output << getNum(i*c + 1, c, k) << ' ';
				}
			}
			output << endl;
		}
	}
	return 0;
}

long long getNum(int start, int c, int base) {
	long long pos = start;
	for(int i = 1; i < c; i++) {
		start++;
		if(start > base) {
			pos = (pos - 1) * base + 1;
		} else {
			pos = (pos - 1) * base + start;
		}
	}

	return pos;
}
