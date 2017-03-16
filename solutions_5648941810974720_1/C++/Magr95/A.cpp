#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
	freopen("A-large.in.txt", "r", stdin);
	freopen("large.txt", "w", stdout);
	int n;
	int number[10];
	int alpha[30];
	cin >> n;
	for (int l = 1; l <= n; l++) {
		printf("Case #%d: ", l);
		for (int i = 0; i < 10; i++) number[i] = 0;
		for (int i = 0; i < 30; i++) alpha[i] = 0;
		string s;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			alpha[s[i]-'A']++;
			if (s[i] == 'Z') number[0]++;
			if (s[i] == 'G') number[8]++;
			if (s[i] == 'U') number[4]++;
			if (s[i] == 'X') number[6]++;
			if (s[i] == 'W') number[2]++;
		}
		number[3] = alpha['H'-'A'] - number[8];
		number[1] = alpha['O'-'A'] - number[2] - number[4] - number[0];
		number[7] = alpha['S'-'A'] - number[6];
		number[5] = alpha['V'-'A'] - number[7];
		number[9] = alpha['I'-'A'] - number[5] - number[6] - number[8];
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < number[i]; j++) cout << i;
		}
		cout << endl;
	}
	return 0;
}