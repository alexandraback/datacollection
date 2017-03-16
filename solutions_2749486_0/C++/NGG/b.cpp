#include <iostream>
using namespace std;

int main(void)
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ti++) {
		int x, y;
		cin >> x >> y;
		cout << "Case #" << ti << ": ";
		if (x > 0) {
			for (int i = 0; i < x; i++) cout << "WE";
		} else {
			for (int i = 0; i < -x; i++) cout << "EW";
		}
		if (y > 0) {
			for (int i = 0; i < y; i++) cout << "SN";
		} else {
			for (int i = 0; i < -y; i++) cout << "NS";
		}
		cout << endl;
	}
	return 0;
}
