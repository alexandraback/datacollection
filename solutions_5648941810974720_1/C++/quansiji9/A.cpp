#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include "stdio.h"

using namespace std;

int main() {
	int t;
	cin >> t;

	char s[2010];
	for (int tcount = 1; tcount <= t; ++tcount) {
		cin >> s;

		int len = strnlen_s(s, 2008);
		int count[26];
		int result[10];
		for (int i = 0; i < 26; ++i)
			count[i] = 0;
		for (int i = 0; i < 10; ++i)
			result[i] = 0;

		for (int i = 0; i < len; ++i)
			++ count[s[i] - 'A'];

		result[0] = count['Z' - 'A'];
		result[2] = count['W' - 'A'];
		result[4] = count['U' - 'A'];
		result[6] = count['X' - 'A'];
		result[8] = count['G' - 'A'];

		result[1] = count['O' - 'A'] - result[0] - result[2] - result[4];
		result[3] = count['H' - 'A'] - result[8];
		result[5] = count['F' - 'A'] - result[4];
		result[7] = count['V' - 'A'] - result[5];
		result[9] = count['I' - 'A'] - result[5] - result[6] - result[8];

		cout << "Case #" << tcount << ": ";
		for (int i = 0; i < 10; ++i)
			for (int j = 0; j < result[i]; ++j)
				cout << (char)('0' + i);
		cout << endl;
	}

	return 0;
}