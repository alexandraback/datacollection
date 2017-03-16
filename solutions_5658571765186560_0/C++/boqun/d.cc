#include <iostream>

using namespace std;

int main()
{
	int T, X, R, C;
	cin >> T;
	for (int n = 1; n <= T; n++) {
		cin >> X >> R >> C;

		if ((R * C) % X != 0)
			goto richard;

		if (X <= 2)
			goto gabriel;

		if (X == 3 && R * C == 3)
			goto richard;

		if (X == 4 && R * C <= 8)
			goto richard;

gabriel:
		cout << "Case #" << n << ": GABRIEL" << endl;
		continue;

richard:
		cout << "Case #" << n << ": RICHARD" << endl;
		continue;
	}
	return 0;
}
