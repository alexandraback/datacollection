

#include"tmp.h"

int main() {

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	cin.sync_with_stdio(false);
	int TC; cin >> TC;

	// 0,2,8,6 -> 7 -> 5 -> 4 -> 1 -> 9 -> 3

	// Z:0 W:2 G:8 X:6
	// R:034
	// N:179
	// V:57
	// S:67
	// O:0124
	// F:45
	for (int tc = 1; tc <= TC; ++tc) {
		vector<int> alp(26, 0);
		string s;
		cin >> s;
		for (char c : s) {
			alp[c-'A'] += 1;
		}
		vector<int> nums(10, 0);
		nums[0] = alp['Z' - 'A'];
		nums[2] = alp['W' - 'A'];
		nums[8] = alp['G' - 'A'];
		nums[6] = alp['X' - 'A'];

		nums[7] = alp['S' - 'A'] - nums[6];

		nums[5] = alp['V' - 'A'] - nums[7];

		nums[4] = alp['F' - 'A'] - nums[5];

		nums[1] = alp['O' - 'A'] - nums[0] - nums[2] - nums[4];

		nums[9] = alp['N' - 'A'] - nums[1] - nums[7];
		nums[9] /= 2;

		nums[3] = alp['R' - 'A'] - nums[0] - nums[4];

		string ans;
		for (int i = 0; i < 10; ++i) {
			ans += string(nums[i], i + '0');
		}

		cout << "Case #" << tc << ": " << ans << endl;
	}

	return 0;
}

