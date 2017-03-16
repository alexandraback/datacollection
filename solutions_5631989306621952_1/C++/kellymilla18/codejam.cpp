#include <bits/stdc++.h>
#define ll long long
#define int ll
#define mod 1000000007
using namespace std;

main(){
	ios::sync_with_stdio(0);
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, c = 1;
	string s;
	
	cin >> t;
	while(t--) {
		cin >> s;
		cout << "Case #" << c++ << ": ";
		string ans = "";
		ans += s[0];
		for(int i = 1; i < s.length(); i++)
			if(s[i] >= ans[0])
				ans = s[i] + ans;
			else
				ans += s[i];
		cout << ans << endl; 	
	}
}

