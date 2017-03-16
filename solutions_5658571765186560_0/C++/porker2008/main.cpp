#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	bool result[4][4][4] = {
		{
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 1, 0, 1, 0 },
			{ 0, 0, 0, 0 },
			{ 1, 0, 1, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 1, 1, 1, 1 },
			{ 1, 1, 0, 1 },
			{ 1, 0, 0, 0 },
			{ 1, 1, 0, 1 }
		},
		{
			{ 1, 1, 1, 1 },
			{ 1, 1, 1, 1 },
			{ 1, 1, 1, 0 },
			{ 1, 1, 0, 0 }
		},
	};
	for (int cas = 1; cas <= T; cas++) {
		int X, R, C;
		cin >> X >> R >> C;
		cout << "Case #" << cas << ": ";
		if (result[X - 1][R - 1][C - 1]) {
			cout << "RICHARD" << endl;
		}
		else {
			cout << "GABRIEL" << endl;
		}
	}
}