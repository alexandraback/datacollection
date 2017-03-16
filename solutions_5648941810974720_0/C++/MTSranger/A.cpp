#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string digits[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int digitLetters[10][30];
int order[10] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};

string computeAns(string str) {
	int letters[26];
	int counts[10];
	memset(letters, 0, sizeof(letters));
	memset(counts, 0, sizeof(counts));
	for (int i = 0; i < str.length(); i++) {
		letters[str[i] - 'A']++;
	}
	for (int i = 0; i < 10; i++) {
		int curr = order[i];
		int mincount = str.length();
		for (int j = 0; j < 26; j++) {
			if (digitLetters[curr][j] > 0) {
				mincount = min(mincount, letters[j] / digitLetters[curr][j]);
			}
		}
		for (int j = 0; j < 26; j++) {
			if (digitLetters[curr][j] > 0) {
				letters[j] -= mincount * digitLetters[curr][j];
			}
		}
		counts[curr] = mincount;
	}
	string res = "";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < counts[i]; j++) {
			res += (char)('0' + i);
		}
	}
	return res;
}

int main() {
	memset(digitLetters, 0, sizeof(digitLetters));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < digits[i].length(); j++) {
			digitLetters[i][digits[i][j] - 'A']++;
		}
	}
	int nc; cin >> nc;
	for (int cs = 1; cs <= nc; cs++) {
		string str; cin >> str;
		string ans = computeAns(str);
		cout << "Case #" << cs << ": " << ans << endl;
	}
}
