// b.cpp

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T;
	int X, Y;

	cin >> T;
	for (int t = 1 ;t <= T ; t++) {
		cin >> X >> Y;

		string ans = "";
		for (int i = 0 ; i < abs(X) ; i++)
			ans += (X > 0 ? "WE" : "EW");
		for (int i = 0 ; i < abs(Y) ; i++)
			ans += (Y > 0 ? "SN" : "NS");
		
		cout << "Case #" << t << ": " << ans << endl;
	}


	return 0;
}