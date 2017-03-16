#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef struct _BIG_INT{
	int b[120];
} BigInt;

vector<BigInt> fslist;
int tested = 0;

// -1 a < b; 0 a==b, 1 a>b
int compare(const BigInt &a, const BigInt &b) {
	for (int i = 119; i >= 0; --i) {
		if (a.b[i] > b.b[i]) {
			return 1;
		} else if (a.b[i] < b.b[i]) {
			return -1;
		}
	}
	return 0;
}

BigInt mult(const BigInt &a, const BigInt &b) {
	BigInt c;
	memset(c.b, 0, sizeof(c.b));
	for (int i = 0; i < 120; ++i) {
		for (int j = 0; j <= i; ++j) {
			c.b[i] += a.b[j] * b.b[i-j];
		}
	}
	for (int i = 0; i < 119; ++i) {
		c.b[i+1] += (c.b[i] / 10);
		c.b[i] %= 10;
	}
	return c;
}

bool testPalindrome(const BigInt &a) {
	int h = 119;
	while (a.b[h] == 0 && h > 0) -- h;
	int i = 0;
	while (h > i) {
		if (a.b[h] != a.b[i]) {
			return false;
		}
		-- h;
		++ i;
	}
	return true;
}

void check(int b, int used1, int used2, int num, BigInt &a) {
	if (b > (num - 1) / 2) {
		++ tested;
		if (used1 + used2 > 0) {
			if (testPalindrome(a) && testPalindrome(mult(a, a))) {
				fslist.push_back(a);
			}
		}
	} else {
		a.b[b] = 0;
		a.b[num - 1 - b] = 0;
		check(b + 1, used1, used2, num, a);
		if (used1 < 5) {
			a.b[b] = 1;
			a.b[num - 1 - b] = 1;
			check(b + 1, used1 + 1, used2, num, a);
		}
		if (used2 < 1) {
			a.b[b] = 2;		
			a.b[num - 1 - b] = 2;
			check(b + 1, used1, used2 + 1, num, a);
		}
		a.b[b] = 0;
		a.b[num - 1 - b] = 0;
	}
}

int t;
BigInt a, b;

int main() {
	fslist.clear();
	BigInt x;
	memset(x.b, 0, sizeof(x.b));
	x.b[0] = 3;
	fslist.push_back(x);
	for (int i = 1; i < 20; ++i) {
		memset(x.b, 0, sizeof(x.b));
		check(0, 0, 0, i, x);
	}
	cin >> t;
	for (int caseNum = 0; caseNum < t; ++caseNum) {
		string sa, sb;
		cin >> sa >> sb;
		memset(a.b, 0, sizeof(a.b));
		memset(b.b, 0, sizeof(b.b));
		for (int i = sa.length() - 1; i >= 0; --i) {
			a.b[sa.length() - 1 - i] = sa[i] - '0';
		}
		for (int i = sb.length() - 1; i >= 0; --i) {
			b.b[sb.length() - 1 - i] = sb[i] - '0';
		}
		int count = 0;
		for (int i = 0; i < fslist.size(); ++i) {
			BigInt c = mult(fslist[i], fslist[i]);
			if (compare(a, c) <= 0 && compare(c, b) <= 0) {
				++ count;
			}
		}
		cout << "Case #" << caseNum + 1 << ": " << count << endl;
	}
	return 0;
}