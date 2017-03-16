#include <bits/stdc++.h>
#define ll long long
#define int ll
#define mod 1000000007
using namespace std;

main(){
	ios::sync_with_stdio(0);
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t, n, c = 1;
	string a[1111];
	string b[1111];
	
	cin >> t;
	while(t--) {
		cin >> n;
		map <string, int> aa;
		map <string, int> bb;
		
		for(int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
			aa[a[i]] = 1;
			bb[b[i]] = 1;
		}
		
		int ans = aa.size() + bb.size();
		for(int i = 0; i < n; i++) {
			if(aa[a[i]] == 1 && bb[b[i]] == 1) {
				ans--;
				aa[a[i]] = 0;
				bb[b[i]] = 0;
			}
		}
		cout << "Case #" << c++ << ": "<< n - ans << endl;
	}
	
}

