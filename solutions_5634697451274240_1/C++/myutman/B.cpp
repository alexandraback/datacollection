#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	for (int ct = 0; ct < t; ct++){
		string s;
		cin >> s;
		int cnt = 0;
		for (int i = 1; i < s.size(); i++){
			cnt += (s[i] != s[i - 1]);
		}
		cnt += (s.back() == '-');
		cout << "case #" << ct + 1 << ": " << cnt << "\n";
	}
	return 0;
}