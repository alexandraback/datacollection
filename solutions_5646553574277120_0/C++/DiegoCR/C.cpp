#include <bits/stdc++.h>

using namespace std;

int val[111];
int can[111];

int main() {

	freopen ( "C.in", "r", stdin );
	freopen ( "SalidaC.txt", "w", stdout );
	
	int ntc;
	int C, D, V;
	
	cin >> ntc;
	
	for ( int tc = 1; tc <= ntc; tc ++ ) {
		
		cin >> C >> D >> V;
		
		for ( int i = 0; i <= V; i ++ ) can[i] = false;
		
		for ( int i = 0; i < D; i ++ )
			cin >> val[i];
		
		int ans = 0;
		
		can[0] = 1;
		
		for ( int i = 0; i < D; i ++ ) {
			for ( int j = V; j >= val[i]; j -- ) {
				can[j] |= can[j - val[i]];
			}
		}
		
		for ( int i = 1; i <= V; i ++ ) {
			if ( can[i] ) continue;
			ans ++;
			for ( int j = V; j >= i; j -- ) {
				can[j] |= can[j - i];
			}
		}
		
		cout << "Case #" << tc << ": " << ans << '\n';
	}
	
	
	return 0;
}
