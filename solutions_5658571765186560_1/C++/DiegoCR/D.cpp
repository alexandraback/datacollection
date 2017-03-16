#include <bits/stdc++.h>

using namespace std;

int main () { 
	
	freopen ( "D.in", "r", stdin );
	freopen ( "SalidaD.txt", "w", stdout );
	
	int X, R, C;
	int ntc;
	
	cin >> ntc;
	
	for ( int tc = 1; tc <= ntc; tc ++ ) {
		
		cin >> X >> R >> C;
		
		if ( R < C ) swap ( R, C );
		
		cout << "Case #" << tc << ": ";
		
		if ( ( R * C ) % X || X > 6 )
			cout << "RICHARD\n";
		else if ( X > R )
			cout << "RICHARD\n";
		else if ( (X + 1) / 2 > C )
			cout << "RICHARD\n";
		else if ( (X + 1) / 2 == C ) {
			
			int w = X - ( X + 1 ) / 2;
			bool imp = false;
			
			for ( int i = 1; i < w && !imp; i ++ ) {
				int j = w - i;
				bool ok = false;
				
				for ( int k = 1; k < R - 1 && !ok; k ++ )
					if ( ( k * C - i ) % X == 0 && ( ( R - k - 1) * C - j ) % X == 0 )
						ok = true;
				
				if ( !ok ) imp = true;
			}
			
			if ( imp ) cout << "RICHARD\n";
			else cout << "GABRIEL\n";
		}
		else 
			cout << "GABRIEL\n";
		
	}
	
	
}
