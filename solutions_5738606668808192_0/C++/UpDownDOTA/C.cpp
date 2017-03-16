#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("C-small-attempt0.in");
ofstream fout("output.txt");

int main() {
	int n, j;
	fin>>n;
	fin>>n;
	fin>>j;

	fout<<"Case #1:\n";
	for (int i = 0; i < j; i++) {
		int tmp = i;
		string s = "11";
		while (tmp) {
			if (tmp % 2)
				s += "11";
			else
				s += "00";
			tmp /= 2;
		}
		while (s.length() < n-2)
			s += "0";
		s += "11";
		fout<<s<<" 3 4 5 6 7 8 9 10 11\n";
	}
}