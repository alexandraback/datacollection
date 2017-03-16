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
			int K, C, S;
			ifile >> K >> C >> S;
			out += "Case #" + to_string(i) + ":";
			for (int j = 1; j <= S; ++j) {
				out += ' ' + to_string(j);
			}
			out += '\n';
		}

		ofstream ofile("txt.out");
		ofile.clear();
		ofile << out;
		ofile.close();

		ifile.close();
	}


	return 0;
}