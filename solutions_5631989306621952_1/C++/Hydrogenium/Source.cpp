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

string proc(string s) {
	if (s.length() <= 1) return s;

	int max = 0;
	for (int i = 1; i < s.length(); ++i)
		if (s[i] >= s[max])
			max = i;

	return s[max] + proc(s.substr(0, max)) + s.substr(max + 1);
}

int main() {
	infile.open("input.txt");
	outfile.open("output.txt");

	infile >> T;

	for (int p = 1; p <= T; ++p) {
		//		reset();

		outfile << "Case #" << p << ": ";

		infile >> s;

		outfile << proc(s);
		
		outfile << endl;
	}

	infile.close();
	outfile.close();
	return 0;
}