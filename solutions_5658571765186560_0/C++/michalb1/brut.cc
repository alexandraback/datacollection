#include <iostream>
using namespace std;

int main() {
	int i, t, x, r, c;
	cin >> t;
	for (i = 1; i <= t; ++i) {
		cin >> x >> r >> c;
		if (x == 1 || (x == 2 && (r * c) % 2 == 0) || (x == 3 && (r % 3 == 0 || c % 3 == 0)
		    && !(r == 1 && c == 3) && !(r == 3 && c == 1)) 
		    || (x == 4 && ((r == 4 && c == 4) || (r == 3 && c == 4) || (r == 4 && c == 3))))
		    cout << "Case #" << i <<": GABRIEL" << std::endl;
		else
		    cout << "Case #" << i <<": RICHARD" << std::endl;
	}
	return 0;
}
