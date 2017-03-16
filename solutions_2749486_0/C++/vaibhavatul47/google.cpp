#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	int t;
	int x, y;
	
	int a, b;
	string n, w, e, s;
	
	cin >> t;
	
	for (int j = 1; j <= t; j++) {
		cin >> x;
		cin >> y;
		
		a = abs(x);
		b = abs(y);
		
		n = "N";
		e = "E";
		s = "S";
		w = "W";
		
		if (x < 0) {
			e = "W";
			w = "E";
		}
		if (y < 0) {
			n = "S";
			s = "N";
		}
		cout << "Case #" << j << ": ";
		for (int i = 1; i <= a; i++) {
			cout << w << e;
		}
		for (int i = 1; i <= b; i++) {
			cout << s << n;
		}
		cout << endl;
	}
	
	return 0;
}