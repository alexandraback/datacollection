#include <iostream>
using namespace std;

int main() {
	int T, X, R, C;
	cin >> T;
	for( int t = 1; t <= T; ++ t) {
		cin >> X >> R >> C;
		if( (R * C) % X != 0) {
			cout << "Case #" << t << ": RICHARD" << endl;
		}
		else if (X == 1 || X == 2){ 
			cout << "Case #" << t << ": GABRIEL" << endl;
		} else if( R == 1 || C == 1 ) {
			cout << "Case #" << t << ": RICHARD" << endl;
		} else if( X == 3 ) {
			cout << "Case #" << t << ": GABRIEL" << endl;
		} else {
			if( R == 2 || C == 2 )
				cout << "Case #" << t << ": RICHARD" << endl;
			else
				cout << "Case #" << t << ": GABRIEL" << endl;
		}
	}
	return 0;
}
