#include <bits/stdc++.h>

using namespace std;

int main() {

	freopen ( "A.in", "r", stdin );
	freopen ( "SalidaA.txt", "w", stdout );
	
	int ntc;
	int R, C, W;
	
	cin >> ntc;
	
	for ( int tc = 1; tc <= ntc; tc ++ ) {
		
		cin >> R >> C >> W;
		
		int ans = C, opc, cont = 0;
		
		while ( C > 2 * W ) {
			cont ++;
			C -= W;
		}
		
		ans = min ( ans, cont + W + 1 );
		/*
		if ( C <= 2 * W )
			ans = min ( ans, W + 1 );
		else
			ans = min ( ans, ( C / W ) + W );
		*/	
		ans *= R;
		
		cout << "Case #" << tc << ": " << ans << '\n';
	}
	
	
	return 0;
}
