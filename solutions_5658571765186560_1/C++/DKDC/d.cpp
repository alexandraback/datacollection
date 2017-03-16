#include <iostream>

using namespace std;

int main(void)
{
	int T, n = 1, X, R, C;

	cin >> T;
	while (n <= T) {
		cin >> X >> R >> C;
		cout << "Case #" << n++ << ": ";
		if (R * C % X != 0) {
			cout << "RICHARD\n";
		} else if ((X+1)/2 > R || (X+1)/2 > C) {
			cout << "RICHARD\n";
		} else if (X > R && X > C) {
			cout << "RICHARD\n";
		} else if (X >= 4 && (R <= X / 2 || C <= X / 2)) {
			cout << "RICHARD\n";
		} else {
			cout << "GABRIEL\n";
		}
	}
	return 0;
}
