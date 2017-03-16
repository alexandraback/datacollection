#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;

	for(int t = 0; t < T; t++){
		int n;
		cin >> n;
		vector<string> a(n), b(n);
		for(int i = 0; i < n; i++)
			cin >> a[i] >> b[i];
		int ans = 0;
		for(int mask = 0; mask < (1<<n); mask++){
			int d = 0;
			set<string> _a, _b;
			for(int i = 0; i < n; i++){
				if( (mask&(1<<i)) ){
					_a.insert(a[i]);
					_b.insert(b[i]);
				}
				else
					d++;
			}
			bool good = true;
			for(int i = 0; i < n; i++)
				if( !(mask&(1<<i)) && (!_a.count(a[i]) || !_b.count(b[i])) )
					good = false;
			if(good)
				ans = max(d, ans);
		}
		cout << "Case #" << t+1 << ": " << ans << endl;
	}

	return 0;
}
