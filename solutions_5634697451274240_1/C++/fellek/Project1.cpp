
#include<iostream>
#include<string>
using namespace std;


bool allAppeared(bool* appeared) {

	for (int k = 0; k < 10; k++) {
		if (!appeared[k])return false;
	}
	return true;
}

void zeroAppeared(bool* appeared) {

	for (int k = 0; k < 10; k++) {
		appeared[k] = false;
	}
}

void evaluate(__int64 current, bool* appeared) {
	while (current > 0) {
		appeared[current % 10] = true;

		current = current / 10;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(true);
	int t;
	cin >> t;
	string s;
	getline(cin,s);

	for (int k = 1; k <= t; k++) {
		getline(cin, s);

		int result = 0;

		for (int l = s.size()-1; l >= 0; l--) {
			if (s[l] == '-') {
				result++;
				for (int m = 0; m <= l; m++) {
					if (s[m] == '-') {
						s[m] = '+';
					}
					else {
						s[m] = '-';
					}
				}
			}
		}

		cout << "Case #" << k << ": " << result << endl;
	}
	return 0;
}

