#include <iostream>
#include <string>

#define ll long long int

using namespace std;


int main()
{
	int TN;
	cin >> TN;
	for (int tc = 0; tc < TN; tc++)
	{
		string ans = "";
		int X, Y;

		cin >> X >> Y;

		string xs, ys;
		if( X > 0 ) {
			xs = "WE";
		} else {
			xs = "EW";
		}
		if( Y > 0 ) {
			ys = "SN";
		} else {
			ys = "NS";
		}

		for( int i=0; i<abs(X); i++ ) {
			ans += xs;
		}
		for( int i=0; i<abs(Y); i++ ) {
			ans += ys;
		}

		cout << "Case #" << tc+1 << ": " << ans << endl;
	}
	return 0;
}