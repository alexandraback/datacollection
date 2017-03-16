
#include <iostream>

using namespace std;

int main() {
	cout.setf( ios::fixed, ios::floatfield );
	cout.precision(7);
	int t;
	cin >> t;
	for (int ti=1; ti<=t; ti++) {
		double c, f, x;
		cin >> c >> f >> x;
		double t = 0;
		double farms = 2;
		while (x/farms > c/farms + x/(farms + f)) {
			t += c/farms;
			farms += f;
		}
		t += x/farms;
		cout << "Case #" << ti << ": " << t << endl;
	}
	return 0;
}
