# include <bits/stdc++.h>
using namespace std;

int main()
{		
	int T; cin >> T;
	for(int T_=1; T_<=T; ++T_) {
		string s; cin >> s;
		
		string ans;
		ans += s[0];
		for(int i=1; i<s.size(); ++i) {
			if (s[i] >= ans[0]) {
				ans = s[i] + ans; 
			}
			else {
				ans = ans + s[i];
			}
		}
		printf("Case #%d: %s\n", T_, ans.c_str());
	}
	
	return 0;
}