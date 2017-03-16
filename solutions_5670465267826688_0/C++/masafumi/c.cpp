#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int ValI = 2;
const int ValJ = 3;
const int ValK = 4;
const int ValIJK = -1;

// i 2, j 3, k 4
const int matrix[5][5] = {
	//x,  1,  i,  j,  k
	{ 0,  0,  0,  0,  0},
	{ 0,  1,  2,  3,  4},
	{ 0,  2, -1,  4, -3},
	{ 0,  3, -4, -1,  2},
	{ 0,  4,  3, -2, -1},
};


int calc(int a, int b) {
	return matrix[abs(a)][abs(b)] * (a * b > 0 ? 1 : -1);
}

int convert(char a) {
	return a - 'g'; // a - 'i' + 2
}


bool solve(long long l, long long x, string basestr) {
	if (l * x < 3) {
		return false;
	}

	string str;
	for (int i = 0; i < x; i++) {
		str += basestr;
	}
	long long len = str.size();

	int a = 1;
	for (long long i = 0; i < len; i++) {
		a = calc(a, convert(str[i]));
	}

	if (a != ValIJK) {
		return false;
	}

	a = 1;
	for (long long i = 0; i < len; i++) {
		a = calc(a, convert(str[i]));
		if (a != ValI) {
			continue;
		}

		int b = 1;
		for (long long j = i + 1; j < len; j++) {
			b = calc(b, convert(str[j]));
			if (b != ValJ) {
				continue;
			}

			int c = 1;
			for (long long k = j + 1; k < len; k++) {
				c = calc(c, convert(str[k]));
			}
			if (c == ValK) {
				return true;
			}
		}
	}

	return false;
}

int main() {

	int t;
	long long l, x;
	string str;

	cin >> t;
	vector<bool> ans(t);

	for (int i = 0; i < t; i++) {
		cin >> l >> x >> str;

		ans[i] = solve(l, x, str);
	}

	for (int i = 0; i < t; i++) {
		printf("Case #%d: %s\n", i + 1, ans[i] ? "YES" : "NO");
	}

	return 0;
}
