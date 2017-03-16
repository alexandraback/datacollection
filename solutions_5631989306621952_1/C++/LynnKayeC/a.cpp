#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

void work(ifstream & fin, ofstream & fout, int caseno) {
	string s;
	fin >> s;
	string t = "";
	for (int i = 0; i < s.size(); ++i) {
		if (t.size() == 0)
			t += s[i];
		else if (t[0] <= s[i])
			t = s[i] + t;
		else
			t += s[i];
	}
	fout << "Case #" << caseno << ": " << t << endl;
}

int main() {
	ifstream fin;
	fin.open("input");
	ofstream fout;
	fout.open("output");
	int testcase;
	fin >> testcase;
	for (int i = 0; i < testcase; ++i) {
		work(fin, fout, i + 1);
	}
	fin.close();
	fout.close();
	return 0;
}