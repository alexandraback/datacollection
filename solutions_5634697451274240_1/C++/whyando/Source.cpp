#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace::std;

ofstream fout("out.txt");
ifstream fin("in.txt");

int T, t;

int main() {

	fin >> T;
	for (t = 1; t <= T; t++) {
		string s;
		fin >> s;
		
		int kinks = 0;
		for (int i = 1; i < s.length(); i++) {
			if (s[i] != s[i - 1])
				kinks++;
		}
		if (s[s.length() - 1] == '-')
			kinks++;

		fout << "Case #" << t << ": " << kinks << endl;
		cout << "Case #" << t << ": " << kinks << endl;
	}
}

