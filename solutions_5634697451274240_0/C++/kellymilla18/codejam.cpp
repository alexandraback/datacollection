#include <bits/stdc++.h>
#define ll long long
#define int ll
#define mod 1000000007
using namespace std;

main(){
	ios::sync_with_stdio(0);
	freopen("output.txt", "w", stdout);
	int t, c = 1;
	cin >> t;
	string s;
	while(t--) {
		cin >> s;
		
		cout << "Case #" << c++ << ": ";
		int r = s.length() - 1;
		while(r >= 0 && s[r] == '+') {
			r--;	
		}
		
		int ans = 0;
		char last = '#';
		for(int i = 0; i <= r; i++) {
			if(last != s[i]) {
				ans++;
				last = s[i];
			}
		}
		
		cout << ans << endl;
	}
}

