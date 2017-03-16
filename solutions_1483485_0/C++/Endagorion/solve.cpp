#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#ifdef ONLINE_JUDGE

#define fin cin
#define fout cout

#else

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

#endif

int main() {
	fout.precision(10);
	fout << fixed;

	int T;
	fin >> T;

	string code = "yhesocvxduiglbkrztnwjpfmaq";
	char s[201];
	fin.getline(s, 200);

	for (int t = 0; t < T; ++t) {
		fin.getline(s, 200);
		for (size_t i = 0; s[i]; ++i) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				s[i] = code[s[i] - 'a'];
			}
		}
		fout << "Case #" << t + 1 << ": " << s << '\n';
	}

	return 0;
}
