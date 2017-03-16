#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

const int N = 10;
const vector <string> NUMS = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
const vector <int> ORDER = {0, 2, 4, 5, 6, 8, 9, 1, 3, 7};
const vector <char> KEY = {'Z', 'W', 'U', 'F', 'X', 'G', 'I', 'O', 'T', 'S'};

void solve(const int t) {
	cout << "Case #" << t << ": ";

	string str;
	cin >> str;

	map<char, int> cnt;
	for each (char ch in str) {
		++cnt[ch];
	}

	vector <int> ans(N);
	for (int i = 0; i < N; ++i) {
		const int dig = ORDER[i];
		int digAns = cnt[KEY[i]];
		ans[dig] += digAns;

		const string& name = NUMS[dig];
		for each (char ch in name) {
			cnt[ch] -= digAns;
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < ans[i]; ++j) {
			cout << i;
		}
	}
	cout << endl;
}

int main() {
	int T = 0;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		solve(i + 1);
	}

	return 0;
}
