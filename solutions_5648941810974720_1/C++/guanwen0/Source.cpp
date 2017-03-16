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
			while (searchDigitInS(5, S))
				sortedNumber.push_back(5);
			while (searchDigitInS(7, S))
				sortedNumber.push_back(7);
			while (searchDigitInS(1, S))
				sortedNumber.push_back(1);
			while (searchDigitInS(3, S))
				sortedNumber.push_back(3);
			while (searchDigitInS(9, S))
				sortedNumber.push_back(9);
		sort(sortedNumber.begin(), sortedNumber.end());

		cout << "Case #" << i + 1 << ": ";
		for (int j = 0; j < sortedNumber.size(); j++)
			cout << sortedNumber.at(j);
		cout << endl;
	}
	return 0;
}