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
	{ 0,  0,  0,  0,  0}, // 0
	{ 0,  1,  2,  3,  4}, // 1
	{ 0,  2, -1,  4, -3}, // i
	{ 0,  3, -4, -1,  2}, // j
	{ 0,  4,  3, -2, -1}, // k
};


int calc(int a, int b) {
	return matrix[abs(a)][abs(b)] * (a * b > 0 ? 1 : -1);
}

int convert(char a) {
	return a - 'g'; // a - 'i' + 2
}


bool solve(long long l, long long x, string baseStr) {
	if (l * x < 3) {
		return false;
	}

	int baseLen = baseStr.size();
	int valBase = 1;
	for (long long i = 0; i < baseLen; i++) {
		valBase = calc(valBase, convert(baseStr[i]));
	}

	int mod4 = x % 4;

	int valStr = 1;
	for (int i = 0; i < x % 4; i++) {
		valStr = calc(valStr, valBase);
	}
	if (valStr != ValIJK) {
		return false;
	}

	string str;
	for (int i = 0; i < min(4LL + mod4, x); i++) {
		str += baseStr;
	}

	int len = str.size();

	int a = 1;
	for (int i = 0; i < len; i++) {
		a = calc(a, convert(str[i]));
		if (abs(a) != ValI) {
			continue;
		}

		int b = 1;
		for (int j = i + 1; j < len; j++) {
			b = calc(b, convert(str[j]));
			if (abs(b) == ValJ) {
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
