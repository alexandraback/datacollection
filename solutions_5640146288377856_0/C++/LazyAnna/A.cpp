#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	int tests;
	int r, c, w;
	cin >> tests;
	for (int t = 1; t <= tests; ++t) {
		cin >> r >> c >> w;
		if ((w == c) || (w == 1)) {
			cout << "Case #" << t << ": " << c << endl;
			continue;
		}
		int x = w * 2 - c;
		if (x >= 0) {
			cout << "Case #" << t << ": " << w + 1 << endl;
			continue;			
		}
		if (c == 5) {
			cout << "Case #" << t << ": " << 4 << endl;
			continue;			
		}
		if (c == 6) {
			cout << "Case #" << t << ": " << 4 << endl;
			continue;			
		}
		if (c == 7) {
			cout << "Case #" << t << ": " << 5 << endl;
			continue;			
		}
		if (c == 8) {
			cout << "Case #" << t << ": " << 5 << endl;
			continue;			
		}
		if (c == 9) {
			if (w == 3)
			    cout << "Case #" << t << ": " << 5 << endl;
			else 
        		cout << "Case #" << t << ": " << 6 << endl;
			continue;			
		}
		if (c == 10) {
			cout << "Case #" << t << ": " << 6 << endl;
			continue;			
		}
		// sort(a, a + d);
	}
	return 0;
}