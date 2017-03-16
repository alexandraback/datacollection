#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	int t; cin >> t;
	for(int tc = 1 ; tc <= t ; tc++) {
		cin >> s;
		string ans = "";
		for(int i = 0 ; i < s.length() ; i++)
			ans = max(ans + s[i],s[i] + ans);
		printf("Case #%d: %s\n",tc,ans.c_str());
	}
	return 0;
}