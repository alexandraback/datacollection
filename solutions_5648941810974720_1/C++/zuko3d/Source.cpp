#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)

int main(void) {
	int T;

	ifstream fin("A-large (2).in");
	ofstream fout("out.txt");
	fin >> T;
	REP(t, T) {
		string s;
		fin >> s;
		vector<int> digits, chars;
		int tmp;
		digits.resize(10, 0);
		chars.resize(256, 0);

		REP(i, s.size()) {
			chars[s[i]]++;
		}

		//zeros
		tmp = chars['Z'];
		chars['Z'] -= tmp;
		chars['E'] -= tmp;
		chars['R'] -= tmp;
		chars['O'] -= tmp;
		digits[0] += tmp;

		//two
		tmp = chars['W'];
		chars['T'] -= tmp;
		chars['W'] -= tmp;
		chars['O'] -= tmp;
		digits[2] += tmp;

		tmp = chars['U'];
		chars['F'] -= tmp;
		chars['O'] -= tmp;
		chars['U'] -= tmp;
		chars['R'] -= tmp;
		digits[4] += tmp;

		tmp = chars['F'];
		chars['F'] -= tmp;
		chars['I'] -= tmp;
		chars['V'] -= tmp;
		chars['E'] -= tmp;
		digits[5] += tmp;

		tmp = chars['G'];
		chars['E'] -= tmp;
		chars['I'] -= tmp;
		chars['G'] -= tmp;
		chars['H'] -= tmp;
		chars['T'] -= tmp;
		digits[8] += tmp;

		tmp = chars['X'];
		chars['S'] -= tmp;
		chars['I'] -= tmp;
		chars['X'] -= tmp;
		digits[6] += tmp;
			
		tmp = chars['V'];
		chars['S'] -= tmp;
		chars['E'] -= tmp;
		chars['V'] -= tmp;
		chars['E'] -= tmp;
		chars['N'] -= tmp;
		digits[7] += tmp;

		tmp = chars['I'];
		chars['N'] -= tmp;
		chars['I'] -= tmp;
		chars['N'] -= tmp;
		chars['E'] -= tmp;
		digits[9] += tmp;

		tmp = chars['H'];
		chars['T'] -= tmp;
		chars['H'] -= tmp;
		chars['R'] -= tmp;
		chars['E'] -= tmp;
		chars['E'] -= tmp;
		digits[3] += tmp;

		tmp = chars['N'];
		chars['O'] -= tmp;
		chars['N'] -= tmp;
		chars['E'] -= tmp;
		digits[1] += tmp;

		fout << "Case #" << t + 1 << ": ";

		REP(i, 10) {
			REP(q, digits[i]) fout << i;
		}
		fout << endl;
	}
	fout.close();
	fin.close();
	return 0;
}
