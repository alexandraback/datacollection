#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <utility>
using namespace std;

int main() {
	int T; cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		int x,y;
		cin >> x >> y;

		cout << "Case #" << tc + 1 << ": ";
		int cx = 0;
		while (cx != x) {
			if (cx < x) {
				cx++;
				cout << "WE";
			} else {
				cx--;
				cout << "EW";
			}
		}

		int cy = 0;
		while (cy != y) {
			if (cy < y) {
				cy++;
				cout << "SN";
			} else {
				cy--;
				cout << "NS";
			}
		}
		cout << endl;
	}
}