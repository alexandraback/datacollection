#include <bits/stdc++.h>

using namespace std;

int main() {
	
	freopen ( "A.in", "r", stdin );
	freopen ( "SalidaA.txt", "w", stdout );

	int ntc;
	int n;
	string cad;
	
	cin >> ntc;
	
	for ( int tc = 1; tc <= ntc; tc ++ ) {
		
		cin >> n >> cad;
		
		int ans = 0, tot = cad[0] - '0';
		
		for ( int i = 1; i <= n; i ++ ) {
			if ( tot < i ) {
				ans += i - tot;
				tot = i;
			}
			tot += cad[i] - '0';
		}
		
		cout << "Case #" << tc << ": " << ans << '\n';
		
	}
	
	return 0;
}
