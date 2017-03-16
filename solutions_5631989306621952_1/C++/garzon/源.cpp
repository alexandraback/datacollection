#include <iostream>
#include <fstream>
#include <string>
#include <map>
#define DIR "D:\\codejam\\"

#define REP(i, n) for(int i=0; i<(n); i++)

using namespace std;

string input;

map<int, string> mem;

string fa(int r) {
	if (mem[r].length() != 0)
		return mem[r];
	if (0 >= r) return "";
	if (0 == r - 1) {
		return string() + input[0];
	}
	string res, tmp;
	res = "";
	for (int i = 0; i < r; i++) {
		tmp = input[i] + fa(i) + input.substr(i+1, r-i-1);
		if (res == "" || tmp > res)
			res = tmp;
	}
	mem[r] = res;
	return res;
}

int main() {
	ifstream is(DIR"A-large (2).in");
	ofstream os(DIR"asmall2_out.txt");

	int n;
	is >> n;
	REP(i, n) {
		is >> input;
		mem.clear();
		os << "Case #" << (i + 1) << ": ";
		os << fa(input.length());
		os << endl;
	}

	return 0;
}