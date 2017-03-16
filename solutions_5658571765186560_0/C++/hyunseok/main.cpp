#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
	int T, t, X, R, C, r, c;
	bool pass;
	string win;

	cin >> T;
	for (t = 0; t < T; t++)
	{
		cin >> X >> R >> C;
		if ( C > R ) swap(R, C);

		pass = true;

		if (X >= 7) pass = false;
		if ((R * C) % X != 0) pass = false;

		for (r = X; r > X / 2; r--)
		{
			c = X - r + 1;

			if (r > R || c > C)
			{
				pass = false;
			}
			else if (r == R && c == C)
			{

			}
			else if (r == R || c == C)
			{
				if (R * C < 3 * X)
				{
					if (r == R && c > 2) pass = false;
					if (c == C && r > 2) pass = false;
				}
			}
		}

		win = "GABRIEL";
		if (!pass) win = "RICHARD";

		cout << "Case #"<< t+1 << ": " << win << endl;

	}

	return 0;
}