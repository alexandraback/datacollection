#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ifstream fin("A-small-attempt0.in"); ofstream fout("output.txt");

	int t;
	fin >> t;

	for (int k = 1; k <= t; k++) {
		int digits[26] = {};
		string s, ans;
		fin >> s;

		for (int i = 0; i < s.size(); i++) digits[s[i] - 'A']++;

		// Zero
		while (digits['Z' - 'A'] > 0) {
			ans += "0";
			digits['Z' - 'A']--;
			digits['E' - 'A']--;
			digits['R' - 'A']--;
			digits['O' - 'A']--;
		}

		// Two
		while (digits['W' - 'A'] > 0) {
			ans += "2";
			digits['T' - 'A']--;
			digits['W' - 'A']--;
			digits['O' - 'A']--;
		}

		// Four
		while (digits['U' - 'A'] > 0) {
			ans += "4";
			digits['F' - 'A']--;
			digits['O' - 'A']--;
			digits['U' - 'A']--;
			digits['R' - 'A']--;
		}

		// Six
		while (digits['X' - 'A'] > 0) {
			ans += "6";
			digits['S' - 'A']--;
			digits['I' - 'A']--;
			digits['X' - 'A']--;
		}

		// Eight
		while (digits['G' - 'A'] > 0) {
			ans += "8";
			digits['E' - 'A']--;
			digits['I' - 'A']--;
			digits['G' - 'A']--;
			digits['H' - 'A']--;
			digits['T' - 'A']--;
		}

		// Three
		while (digits['T' - 'A'] > 0) {
			ans += "3";
			digits['T' - 'A']--;
			digits['H' - 'A']--;
			digits['R' - 'A']--;
			digits['E' - 'A']--;
			digits['E' - 'A']--;
		}

		// Seven
		while (digits['S' - 'A'] > 0) {
			ans += "7";
			digits['S' - 'A']--;
			digits['E' - 'A']--;
			digits['V' - 'A']--;
			digits['E' - 'A']--;
			digits['N' - 'A']--;
		}

		// Five
		while (digits['V' - 'A'] > 0) {
			ans += "5";
			digits['F' - 'A']--;
			digits['I' - 'A']--;
			digits['V' - 'A']--;
			digits['E' - 'A']--;
		}

		// Nine
		while (digits['I' - 'A'] > 0) {
			ans += "9";
			digits['N' - 'A']--;
			digits['I' - 'A']--;
			digits['N' - 'A']--;
			digits['E' - 'A']--;
		}

		// One
		while (digits['N' - 'A'] > 0) {
			ans += "1";
			digits['O' - 'A']--;
			digits['N' - 'A']--;
			digits['E' - 'A']--;
		}

		sort(ans.begin(), ans.end());
		fout << "Case #" << k << ": " << ans << endl;
	}

	fin.close(); fout.close();
	return 0;
}