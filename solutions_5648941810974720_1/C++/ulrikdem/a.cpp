#include <bits/stdc++.h>
using namespace std;

void solve() {
	string input;
	cin >> input;
	map<char, int> letters;
	for(char letter : input) {
		++letters[letter];
	}
	int digits[10];
	digits[0] = letters['Z'];
	for(char letter : "ZERO") {
		letters[letter] -= digits[0];
	}
	digits[2] = letters['W'];
	for(char letter : "TWO") {
		letters[letter] -= digits[2];
	}
	digits[4] = letters['U'];
	for(char letter : "FOUR") {
		letters[letter] -= digits[4];
	}
	digits[1] = letters['O'];
	for(char letter : "ONE") {
		letters[letter] -= digits[1];
	}
	digits[3] = letters['R'];
	for(char letter : "THREE") {
		letters[letter] -= digits[3];
	}
	digits[5] = letters['F'];
	for(char letter : "FIVE") {
		letters[letter] -= digits[5];
	}
	digits[6] = letters['X'];
	for(char letter : "SIX") {
		letters[letter] -= digits[6];
	}
	digits[7] = letters['S'];
	for(char letter : "SEVEN") {
		letters[letter] -= digits[7];
	}
	digits[8] = letters['G'];
	for(char letter : "EIGHT") {
		letters[letter] -= digits[8];
	}
	digits[9] = letters['I'];
	for(char letter : "NINE") {
		letters[letter] -= digits[9];
	}
	cout << ' ';
	for(int digit = 0; digit < 10; ++digit) {
		while(digits[digit]--) {
			cout << (char) (digit + '0');
		}
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	int cases;
	cin >> cases;
	for(int i = 1; i <= cases; ++i) {
		cout << "Case #" << i << ':';
		solve();
	}
	return 0;
}
