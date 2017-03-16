#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <map>

using namespace std;
void decrease(map<char, int> &alpha, int minus, string numstr) {
	for (int i = 0; i < numstr.size(); i++) {
		alpha[numstr[i]] -= minus;
	}
}

string solve(string &s) {
	map<char, int> alpha;
	for (int i = 0; i < s.size(); i++) {
		alpha[s[i]]++;
	}

	vector<int> nums(10, 0);
	nums[0] = alpha['Z'];
	decrease(alpha, nums[0], "ZERO");

	nums[2] = alpha['W'];
	decrease(alpha, nums[2], "TWO");

	nums[4] = alpha['U'];
	decrease(alpha, nums[4], "FOUR");

	nums[5] = alpha['F'];
	decrease(alpha, nums[5], "FIVE");

	nums[6] = alpha['X'];
	decrease(alpha, nums[6], "SIX");

	nums[7] = alpha['V'];
	decrease(alpha, nums[7], "SEVEN");

	nums[8] = alpha['G'];
	decrease(alpha, nums[8], "EIGHT");

	nums[9] = alpha['I'];
	decrease(alpha, nums[9], "NINE");

	nums[1] = alpha['O'];
	decrease(alpha, nums[1], "ONE");

	nums[3] = alpha['T'];
	decrease(alpha, nums[3], "THREE");

	string ans;
	for (int i = 0; i < nums.size(); i++) {
		ans += string(nums[i], i + '0');
	}

	return ans;
}

int main() {
	int t;
	string s;

	cin >> t;
	vector<string> ans(t);
	for (int i = 0; i < t; i++) {
		cin >> s;
		ans[i] = solve(s);
	}

	for (int i = 0; i < t; i++) {
		printf("Case #%d: %s\n", i + 1, ans[i].c_str());
	}
	return 0;
}
