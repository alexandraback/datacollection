#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string numbers[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

bool searchDigitInS(int digit, string &S) {
	string number = numbers[digit];
	
	bool *hasChecked = new bool[S.length()];
	for (int i = 0; i < S.length(); i++)
		hasChecked[i] = false;
	
	int count = 0;
	for (int i = 0; i < number.length(); i++) {
		for (int j = 0; j < S.length(); j++) {
			if (number.at(i) == S.at(j) && !hasChecked[j]) {
				count++;
				hasChecked[j] = true;
				break;
			}
		}
	}

	string newS;
	if (count == number.length()) {
		for (int i = 0; i < S.length(); i++) {
			if (!hasChecked[i])
				newS.push_back(S.at(i));
		}
		S = newS;
		return true;
	}
	else
		return false;
}

int main(void) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		vector<int> sortedNumber;
		sortedNumber.clear();
		string S;
		cin >> S;
		while (S.length() > 0) {
			while (searchDigitInS(0, S))
				sortedNumber.push_back(0);
			while (searchDigitInS(2, S))
				sortedNumber.push_back(2);
			while (searchDigitInS(4, S))
				sortedNumber.push_back(4);
			while (searchDigitInS(6, S))
				sortedNumber.push_back(6);
			while (searchDigitInS(8, S))
				sortedNumber.push_back(8);
			for (int j = 0; j < 10; j++) {
				if (j == 0 || j == 2 || j == 4 || j == 6 || j == 8)
					continue;
				if (searchDigitInS(j, S))
					sortedNumber.push_back(j);
			}
		}
		sort(sortedNumber.begin(), sortedNumber.end());

		cout << "Case #" << i + 1 << ": ";
		for (int j = 0; j < sortedNumber.size(); j++)
			cout << sortedNumber.at(j);
		cout << endl;
	}
	return 0;
}