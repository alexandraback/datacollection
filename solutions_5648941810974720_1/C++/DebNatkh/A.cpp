#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

string name[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

string answer() {
	string s;
	cin >> s;
	map<char, int> m;
	for (int i = 0; i < (int)s.size(); i++) {
		m[s[i]] += 1;
	}
	vector<int> answ(10, 0);
	
	answ[0] = m['Z'];
	for (char c : name[0]) {
		m[c] -= answ[0];
	}
	answ[6] = m['X'];
	for (char c : name[6]) {
		m[c] -= answ[6];
	}
	answ[8] = m['G'];
	for (char c : name[8]) {
		m[c] -= answ[8];
	}
	answ[7] = m['S'];
	for (char c : name[7]) {
		m[c] -= answ[7];
	}
	answ[5] = m['V'];
	for (char c : name[5]) {
		m[c] -= answ[5];
	}
	answ[4] = m['F'];
	for (char c : name[4]) {
		m[c] -= answ[4];
	}
	answ[2] = m['W'];
	for (char c : name[2]) {
		m[c] -= answ[2];
	}
	answ[3] = m['H'];
	for (char c : name[3]) {
		m[c] -= answ[3];
	}
	answ[1] = m['O'];
	for (char c : name[1]) {
		m[c] -= answ[1];
	}
	answ[9] = m['I'];
	for (char c : name[9]) {
		m[c] -= answ[9];
	}
	s = "";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < answ[i]; j++) {
			s += ('0' + i);
		}
	}
	return s;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": " << answer() << endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}