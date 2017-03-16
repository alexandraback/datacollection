#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	int numCases;
	cin >> numCases;

	for(int c = 0; c < numCases; c++) {
		int x, y;
		cin >> x >> y;

		string s = "";
		if ( x > 0 ) {
			for(int i = 0; i < x; i++) {
				s += "WE";
			}
		} else {
			for(int i = 0; i < -x; i++) {
				s += "EW";
			}
		}
		if ( y > 0 ) {
			for(int i = 0; i < y; i++) {
				s += "SN";
			}
		} else {
			for(int i = 0; i < -y; i++) {
				s += "NS";
			}
		}

		printf("Case #%d: ", c+1);
		cout << s << endl;
	}

	return 1;
}