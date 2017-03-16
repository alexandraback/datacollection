#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {

	ifstream cin("probDsmall.in");
	ofstream cout("probDsmall.txt");

	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int X, R, C;
		cin >> X >> R >> C;

		stringstream casenum;
		casenum << t + 1;
		string casenumstr = casenum.str();
		string possible = "Case #" + casenumstr + ": GABRIEL";
		string impossible = "Case #" + casenumstr + ": RICHARD";

		if(X == 1) cout << possible << endl;
		else if(X == 2)
		{
			if(R * C % 2 == 0) cout << possible << endl;
			else cout << impossible << endl;
		}
		else if(X == 3)
		{
			if(R * C % 3 == 0 && R * C != 3) cout << possible << endl;
			else cout << impossible << endl;
		}
		else if(X == 4)
		{
			if(R * C == 16 || R * C == 12) cout << possible << endl;
			else cout << impossible << endl;
		}

	}

	return 0;
}
