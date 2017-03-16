#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	ifstream ifile("txt.in");

	if (ifile.is_open()) {
		string out = "";
		int tests;
		ifile >> tests;

		for (int i = 1; i <= tests; ++i) {
			string  pile;
			ifile >> pile;
			char current = pile[0];
			int it = 0;
			int cnt = 0;
			while (it < pile.length()) {
				if (current != pile[it]) {
					++cnt;
					current = (current == '-') ? '+' : '-';
				}
				++it;
			}
			if (current == '-')
				++cnt;
			out += "Case #" + to_string(i) + ": " + to_string(cnt) + '\n';
		}

		ifile.close();

		ofstream ofile("txt.out");
		ofile.clear();
		ofile << out;
		ofile.close();
	}

	return 0;
}