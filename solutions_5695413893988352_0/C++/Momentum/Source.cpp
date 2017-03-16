#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int n1, n2, n, diff = 1000000;
string s1, s2;

void solve(string s, int idx) {
	if (idx == n) {
		int x1 = stoi(s.substr(0, s1.size()));
		int x2 = stoi(s.substr(s1.size(), n));

		int d = abs(x1 - x2);

		if (d < diff) {
			diff = d;
			s1 = s.substr(0, s1.size());
			s2 = s.substr(s1.size(), n);
			n1 = x1;
			n2 = x2;
		}
		else if (d == diff) {
			if (x1 < n1) {
				s1 = s.substr(0, s1.size());
				s2 = s.substr(s1.size(), n);
				n1 = x1;
				n2 = x2;
			}
			else if (x1 == n1 && x2 < n2) {
				s1 = s.substr(0, s1.size());
				s2 = s.substr(s1.size(), n);
				n1 = x1;
				n2 = x2;
			}
		}
		return;
	}

	if (s[idx] != '?') {
		solve(s, idx + 1);
	}
	else {
		for (int i = 0; i < 10; i++) {
			string t = s;
			t[idx] = '0' + i;

			solve(t, idx + 1);
		}
	}	
}

int main() {
	ifstream fin("B-small-attempt1.in"); ofstream fout("output.txt");

	int t;
	fin >> t;

	for (int k = 1; k <= t; k++) {
		fin >> s1 >> s2;
		n = s1.size() + s2.size(), diff = 1000000;
		solve(s1 + s2, 0);
		fout << "Case #" << k << ": " << s1 << ' ' << s2 << endl;
	}

	fin.close(); fout.close();
	return 0;
}