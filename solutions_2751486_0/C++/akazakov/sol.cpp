#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

inline bool isVowel(char x) {
	return x == 'a' || x == 'o' || x == 'e' || x == 'u' || x == 'i';
}

void solveTestCase() {
	string s;
	int n;
	cin >> s >> n;
	long long res = 0;
	for (int i = 0; i < s.size(); ++i) {
		for (int j = i + n - 1; j <= s.size(); ++j) {
			int z = 0;
			for (int k = i; k < j; ++k) {
				if (!isVowel(s[k])) {
					++z;
				} else {
					z = 0;
				}
				if (z == n) {
					++res;
					break;
				}
			}
		}
	}
	cout << res;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cout << "Case #" << (i + 1) << ": ";
		solveTestCase();
		cout << endl;
	}
	return 0;
}