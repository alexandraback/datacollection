#include <bits/stdc++.h>
#define ll long long
#define int ll
#define mod 1000000007
using namespace std;

bool valid(int a, string b) {
	stringstream ss;
	ss << a;
	string ne;
	ss >> ne;
	while(ne.length() < b.length()) {
		ne = '0' + ne;
	}
	for(int i = 0; i < b.length(); i++)
		if(b[i] != '?' && ne[i] != b[i])
			return false;
	return true;
}

main(){
	ios::sync_with_stdio(0);
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("output1.txt", "w", stdout);
	int t, c = 1;
	string a, b;
	cin >> t;
	while(t--) {
		cin >> a >> b;
		int len = a.length();
		int limit = 1;
		for(int i = 0; i < len; i++)
			limit *= 10;
		
		int diff = 1000000;
		int ansa, ansb;
		for(int i = 0; i < limit; i++) {
			if(valid(i, a)) {
				for(int j = 0; j < limit; j++) {
					 if(valid(j, b)) {
						if(diff > abs(i-j)) {
							ansa = i;
							ansb = j;
							diff = abs(i-j);
						}
					}
				}
			}
		}
		
		cout << "Case #" << c++ << ": ";
		stringstream ssa, ssb;
		ssa << ansa;
		ssb << ansb;
		string ans1, ans2;
		ssa >> ans1;
		ssb >> ans2;
		while(ans1.length() != len)
			ans1 = '0' + ans1;
		while(ans2.length() != len)
			ans2 = '0' + ans2;
		
		
		cout << ans1 << " " << ans2 << endl;
	}
}

