#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int a[4][4] = {
	{0, 1, 2, 3},
	{1, 0, 3, 2},
	{2, 3, 0, 1},
	{3, 2, 1, 0}
};

int p[4][4] = {
	{1, 1, 1, 1},
	{1,-1, 1,-1},
	{1,-1,-1, 1},
	{1, 1,-1,-1}
};


struct Number {
	int value;
	int sign;
	Number() : value(0), sign(1) {
	}
	Number(int value, int sign) : value(value), sign(sign) {
	}

	bool operator == (const Number &other) const {
		return value == other.value && sign == other.sign;
	}
};

Number mul(const Number &X, const Number &Y) {
	return Number(a[X.value][Y.value], X.sign * Y.sign * p[X.value][Y.value]);
}

void solve(int test) {
	long long l, x;
	cin >> l >> x;
	string s;
	cin >> s;
	vector < int > p(l);
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'i') {
			p[i] = 1;
		}
		if (s[i] == 'j') {
			p[i] = 2;
		}
		if (s[i] == 'k') {
			p[i] = 3;
		}
	}

	Number current(0, 1);
	Number total(0, 1);
	for (long long j = 0; j < x % 4; ++j) {
		for (int i = 0; i < l; ++i) {
			current = mul(current, Number(p[i], 1));
		}
		if (j == 0) {
			total = current;
		}
	}
	if (!(current == Number(0, -1))) {
		printf("Case #%d: NO\n", test);
		return;
	}

	long long cnti = -1, leni = -1, cntk = -1, lenk = -1;
	for (int i = 0; i < 4 && cnti == -1; ++i) {
		Number current(0, 1);
		for (int j = 0; j < i; ++j) {
			current = mul(current, total);
		}
		if (current == Number(1, 1)) {
			cnti = i;
			leni = 0;
			break;
		}
		for (int j = 0; j < l; ++j) {
			current = mul(current, Number(p[j], 1));
			if (current == Number(1, 1)) {
				cnti = i;
				leni = j + 1;
				break;
			}
		}
	}

	for (int i = 0; i < 4 && cntk == -1; ++i) {
		Number current(0, 1);
		for (int j = 0; j < i; ++j) {
			current = mul(current, total);
		}
		if (current == Number(3, 1)) {
			cntk = i;
			lenk = 0;
			break;
		}

		Number buffer(0, 1);
		for (int j = l - 1; j >= 0; --j) {
			buffer = mul(Number(p[j], 1), buffer);
			if (mul(buffer, current) == Number(3, 1)) {
				cntk = i;
				lenk = l - j;
				break;
			}
		}
	}

	if (cnti == -1 || cntk == -1) {
		printf("Case #%d: NO\n", test);
		return;
	}

	long long res = x * l;
	res -= l * (cnti + cntk);
	res -= leni + lenk;
	if (res > 0) {
		printf("Case #%d: YES\n", test);
		return;
	} else {
		printf("Case #%d: NO\n", test);
		return;
	}
}

void solve2(int test) {
	long long l, x;
	cin >> l >> x;
	string s;
	cin >> s;
	vector < int > p(l * x);
	for (int j = 0; j < x; ++j) {
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == 'i') {
				p[j * l + i] = 1;
			}
			if (s[i] == 'j') {
				p[j * l + i] = 2;
			}
			if (s[i] == 'k') {
				p[j * l + i] = 3;
			}
		}
	}

	int n = l * x;
	Number total(0, 1);
	for (int i = 0; i < n; ++i) {
		total = mul(total, Number(p[i], 1));
	}
	if (!(total == Number(0, -1))) {
		printf("Case #%d: NO\n", test);
		return ;
	}

	int cnti = -1, cntk = -1;
	{
		Number current(0, 1);
		for (int i = 0; i < n; ++i) {
			current = mul(current, Number(p[i], 1));
			if (current == Number(1, 1)) {
				cnti = i + 1;
				break;
			}
		}
	}
	{
		Number current(0, 1);
		for (int i = n - 1; i >= 0; --i) {
			current = mul(Number(p[i], 1), current);
			if (current == Number(3, 1)) {
				cntk = n - i;
				break;
			}
		}
	}

	if (cnti != -1 && cntk != -1 && cnti + cntk < n) {
		printf("Case #%d: YES\n", test);
	} else {
		printf("Case #%d: NO\n", test);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int i = 0; i < tests; ++i) {
		solve(i + 1);
		cerr << (i + 1) << endl;
	}
	cerr << "Time: " << clock() << endl;
	return 0;
}