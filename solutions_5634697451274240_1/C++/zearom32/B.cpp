#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;



void solve(ifstream& fin, ofstream& fout) {
	string s;
	getline(fin, s);
	int ans = 0;
	int ed = s.length() - 1;
	for (auto& c : s) {
		c = c == '+';
	}
	while (ed >= 0) {
		if (s[ed] == 1) 
			ed--;
		else if (s[0] == 0) {
			std::for_each(s.begin(), s.begin() + ed + 1, [](char &c) {c ^= 1; });
			std::reverse(s.begin(), s.begin() + ed + 1);
			ans++;
		}
		else {
			for (int i = 0; i <= ed; i++)
				if (s[i] == 0) break;
			else
				s[i] ^= 1;
			ans++;
		}
	}
	fout << ans << endl;
}

int main(int argc, char *argv[])
{
	const char* inn;
	if (argc < 2) {
		inn = "b.in";
	}
	else {
		inn = argv[1];
	}
	string in = inn;
	string out = in.replace(in.find(".in"), in.length(), ".out");
	ifstream fin(inn);
	ofstream fout(out);

	int t;
	fin >> t;
	string s;
	getline(fin, s);
	for (int cs = 1; cs <= t; cs++) {
		fout << "Case #" << cs << ": ";
		solve(fin, fout);
	}
	fout.close();

	return 0;
}