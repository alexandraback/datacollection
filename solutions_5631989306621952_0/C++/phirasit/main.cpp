#include <iostream>

using namespace std;

void solve(int);

int main() {
	int t;
	cin >> t;
	for(int case_id = 1;case_id <= t;case_id++) {
		solve(case_id);
	}
	return 0;
}

void solve(int case_id) {
	string str;
	cin >> str;

	string ans = "";
	for(int i = 0;i < str.length();i++) {
		string ch = str.substr(i, 1); 
		if(str == "") {
			ans = ch;
		}else {
			string s1 = ans + ch;
			string s2 = ch + ans;
			ans = max(s1, s2);
		}
	}

	cout << "Case #" << case_id << ": " << ans << "\n";
}