#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
	int T;
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";

		int x, y;
		cin >> x >> y;

		for (int i = 0; i < abs(x); i++) {
			if (i == abs(x) - 1) {
				cout << (x > 0 ? "E" : "W");
			} else {
				cout << (x > 0 ? "EW" : "WE");
			}
		}

		for (int i = 0; i < abs(y); i++) {
			cout << (y > 0 ? "SN" : "NS");
		}
		cout << endl;

	}

	return 0;
}