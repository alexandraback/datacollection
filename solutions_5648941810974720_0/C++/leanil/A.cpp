#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int T;
	in >> T;
	for (int test = 1; test <= T; test++) {
		out << "Case #" << test << ": ";
		string s;
		in >> s;
		vector<char> c(256,0);
		for (char x : s) {
			++c[x];
		}
		vector<int> n(10, 0);
		n[0] = c['Z'];
		n[2] = c['W'];
		n[6] = c['X'];
		n[8] = c['G'];
		n[3] = c['H'] - n[8];
		n[7] = c['S'] - n[6];
		n[5] = c['V'] - n[7];
		n[4] = c['F'] - n[5];
		n[1] = c['O'] - n[0] - n[2] - n[4];
		n[9] = (c['N'] - n[1] - n[7]) / 2;
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < n[i]; ++j) {
				out << i;
			}
		}
		out << endl;
	}
}