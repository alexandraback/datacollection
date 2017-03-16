#include <iostream>
#include <string>

using namespace std;

long long pow_10(int k) {
	long long ans = 1;
	for (int i = 0; i < k; ++i) {
		ans *= (long long)(10);
	}
	return ans;
}

string my_to_string(int n, int p_len) {
	string n_str = to_string(n);
	while (n_str.length() < p_len) {
		n_str = "0" + n_str;
	}
	return n_str;
}

bool matches(string pattern, string str) {
	bool ans = true;
	for (int i = 0; i < pattern.length(); ++i) {
		ans = ans && ((pattern[i] == str[i]) || (pattern[i] == '?'));
	}
	return ans;
}

long long my_abs(long long x) {
	return (x >= 0) ? x : -x;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int best_score_diff = 1000;
		string ans_c, ans_j;
		string pattern_c, pattern_j;
		cin >> pattern_c >> pattern_j;
		int p_len = pattern_c.length();
		//cout << "solving" << endl;
		//cout << p_len << endl;
		for (long long c = 0; c < pow_10(p_len); ++c) {
			for (long long j = 0; j < pow_10(p_len); ++j) {
				string cur_c = my_to_string(c, p_len);
				string cur_j = my_to_string(j, p_len);
				//cout << cur_c << " " << cur_j << endl;
				if (matches(pattern_c, cur_c) 
					&& matches(pattern_j, cur_j)
					&& my_abs(c - j) < best_score_diff) {
					ans_c = cur_c;
					ans_j = cur_j;
					best_score_diff = my_abs(c - j);
				}
			}
		}
		cout << "Case #" << t << ": " << ans_c << " " << ans_j << endl;
	}
	return 0;
}