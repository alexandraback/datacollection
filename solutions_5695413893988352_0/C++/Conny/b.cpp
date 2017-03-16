#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

string s1, s2;

void output(int n, int len) {
	if (len > 0) {
		output(n / 10, len - 1);
		cout << n % 10;
	}
}

bool matched(int n, string s) {
	reverse(s.begin(), s.end());

	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '?' && n % 10 != s[i] - '0')
			return false;
		n /= 10;
	}

	return n == 0;
}

int main() {
	/*
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	*/

	/*
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	*/

	
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("B-small-attempt2.out", "w", stdout);


	/*
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	*/
	int nCases;
	cin >> nCases;

	for (int i = 1; i <= nCases; i++) {
		cout << "Case #" << i << ": ";

		cin >> s1 >> s2;

		int diff = 10000;
		int num1, num2;
		for (int i = 0; i < 1000; i++) {
			for (int j = 0; j < 1000; j++) {
				if (abs(i - j) < diff) {
					if (matched(i, s1) && matched(j, s2)) {
						diff = abs(i - j);
						num1 = i;
						num2 = j;
					}
				}
			}
		}

		output(num1, s1.length());
		cout << ' ';
		output(num2, s2.length());
		
		cout << endl;
	}

	return 0;
}
