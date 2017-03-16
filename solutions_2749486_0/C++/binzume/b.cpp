#include <iostream>
#include <string>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t=0; t<T; t++) {
		int X,Y;
		cin >> X >> Y;

		// ENWSEN  (1,0) (1,2) (-2,2) ()
		
		string ans = "";

		while ( X > 0) {
			ans += "WE";
			X--;
		}
		while ( X < 0) {
			ans += "EW";
			X++;
		}
	
		while ( Y > 0) {
			ans += "SN";
			Y--;
		}
		while ( Y < 0) {
			ans += "NS";
			Y++;
		}

		cout << "Case #" << (t+1) << ": " << ans << endl;
	
	}

	return 0;
}


