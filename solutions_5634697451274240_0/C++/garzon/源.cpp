#include <iostream>
#include <fstream>
#include <string>
#define DIR "D:\\codejam\\"

#define REP(i, n) for(int i=0; i<(n); i++)

using namespace std;

string stack;

inline char inverse(char c) {
	return c == '+' ? '-' : '+';
}

void flip(int l) {
	string tmp = stack;
	REP(i, l) {
		tmp[i] = inverse(stack[l-i-1]);
	}
	stack = tmp;
}

int fb(int len) {
	int res = 0;
	bool ok = true;
	if (len == 0) return 0;
	if (len == 1) {
		return stack[0] == '+' ? 0 : 1;
	}
	int lp;
	for (int i = len - 1; i >= 0; i--) {
		if (stack[i] != '+') {
			ok = false;
			lp = i;
			break;
		}
	}
	if (ok) return 0;
	if (stack[0] == '+') {
		int p;
		REP(i, len) {
			if (stack[i] != '+') {
				p = i;
				break;
			}
		}
		flip(p);
		res = 1;
	}
	flip(lp+1);
	res += 1;
	return res + fb(lp);
}

int main() {
	ifstream is(DIR"B-small-attempt1.in");
	ofstream os(DIR"bsmall_out.txt");

	int n;
	is >> n;
	REP(i, n) {
		is >> stack;
		int tmp = fb(stack.length());
		os << "Case #" << (i + 1) << ": ";
		os << tmp;
		os << endl;
	}

	return 0;
}