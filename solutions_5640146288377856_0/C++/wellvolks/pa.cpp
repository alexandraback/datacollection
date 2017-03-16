#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t, k = 1, r, c, w;
	cin >> t;
	while( t-- ){
		cin >> r >> c >> w;
		int ans = 0;
		for( int i = 0; i < r; i++ ){
			for( int j = 0; j < c; j += w ){
				ans++;
			}
		}
		ans += w-1;
		cout << "Case #" << k++ << ": " << ans << '\n';
	}
	return 0;
}