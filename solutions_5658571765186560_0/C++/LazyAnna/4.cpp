#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int tests;
	int x, r, c;
	cin >> tests;
	for (int t = 1; t <= tests; ++t) {
		cin >> x >> r >> c;
		if (r > c) swap(r, c);
		if (x >= 7) {
			cout << "Case #" << t << ": RICHARD" << endl;
			continue;
		}
		if (x == 1) {
			cout << "Case #" << t << ": GABRIEL" << endl;
			continue;		
		}
		if (x == 2) {
			if (r * c % 2 == 0)
				cout << "Case #" << t << ": GABRIEL" << endl;
			else
				cout << "Case #" << t << ": RICHARD" << endl;				
			continue;		
		}		
		if (x == 3) {
			if (((r % 3 == 0) || (c % 3 == 0)) && (r > 1)) 
				cout << "Case #" << t << ": GABRIEL" << endl;
			else
				cout << "Case #" << t << ": RICHARD" << endl;
			continue;				
		}
		if ((r * c) % x != 0) {
			cout << "Case #" << t << ": RICHARD" << endl;
			continue;			
		}
		if (x == 4) {
			if ((r % 4 == 0) || (c % 4 == 0)) {
				if (r >= 3)
					cout << "Case #" << t << ": GABRIEL" << endl;
				else
					cout << "Case #" << t << ": RICHARD" << endl;
				continue;
			}		
			if (r == 2) {
				cout << "Case #" << t << ": RICHARD" << endl;
				continue;
			}
			cout << "Case #" << t << ": GABRIEL" << endl;	
			continue;			
		}
		if (x == 5) {
			if ((r == 5) || (c == 5)) {
				if (r >= 4)
					cout << "Case #" << t << ": GABRIEL" << endl;
				else
					cout << "Case #" << t << ": RICHARD" << endl;
				continue;
			}
			if (r <= 2) {
				cout << "Case #" << t << ": RICHARD" << endl;
				continue;				
			}
			cout << "Case #" << t << ": GABRIEL" << endl;	
			continue;					
		}
		// x = 6
		

	}
	return 0;
}