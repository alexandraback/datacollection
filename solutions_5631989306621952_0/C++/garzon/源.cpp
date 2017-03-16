#include <iostream>
#include <fstream>
#include <string>
#include <map>
#define DIR "D:\\codejam\\"

#define REP(i, n) for(int i=0; i<(n); i++)

using namespace std;

string input;

map<pair<int, int>, string> mem;

string fa(int l, int r) {
	if (mem[make_pair(l, r)].length() != 0)
		return mem[make_pair(l, r)];
	if (l >= r) return "";
	if (l == r - 1) {
		return string() + input[l];
	}
	string res, tmp;
	res = "";
	for (int i = l; i < r; i++) {
		tmp = input[i] + fa(l, i) + input.substr(i+1, r-i-1);
		if (res == "" || tmp > res)
			res = tmp;
	}
	mem[make_pair(l, r)] = res;
	return res;
}

int main() {
	ifstream is(DIR"A-small-attempt0 (1).in");
	ofstream os(DIR"asmall_out.txt");

	int n;
	is >> n;
	REP(i, n) {
		is >> input;
		mem.clear();
		os << "Case #" << (i + 1) << ": ";
		os << fa(0, input.length());
		os << endl;
	}

	return 0;
}