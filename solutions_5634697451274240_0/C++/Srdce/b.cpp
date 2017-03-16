#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for( int ca = 1 ; ca <= t ; ca++ ) {
		string s;
		cin >> s;
		int ans = 0;
		for( int len = s.length() , i = len-1 ; i >= 0 ; i-- )
			if( ( s[i] == '-' )^(ans&1) )
				ans++;
		cout << "Case #" << ca << ": " << ans << endl;
	}
	return 0;
}
