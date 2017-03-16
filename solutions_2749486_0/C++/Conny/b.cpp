#include <iostream>
#include <fstream>
using namespace std;

#define cin fin
#define cout fout
ifstream fin("B-small-attempt0.in");
ofstream fout("B-small-attempt0.out");

int main() {
	int nCases;
	cin >> nCases;

	for (int cnt = 1; cnt <= nCases; cnt++) {
		int x, y;
		cin >> x >> y;

		cout << "Case #" << cnt << ": ";
		if (x > 0) {
			for (int i = 0; i < x; i++) {
				cout << "WE";
			}
		} else if (x < 0)  {
			for (int i = 0; i < -x; i++) {
				cout << "EW";
			}
		}

		if (y > 0) {
			for (int i = 0; i < y; i++) {
				cout << "SN";
			}
		} else if (y < 0) {
			for (int i = 0; i < -y; i++) {
				cout << "NS";
			}
		}

		cout << endl;
	}

	return 0;
}
