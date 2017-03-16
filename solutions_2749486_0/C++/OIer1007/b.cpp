#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int t;
	cin >> t;
	for (int l = 1; l <= t; l++) {
		int x, y;
		cin >> x >> y;
		cout << "Case #" << l << ": ";
		if (x > 0) {
			cout << "E";
			for (int i = 1; i < x; i++) cout << "WE";
		}
		if (x < 0) {
			cout << "W";
			for (int i = 1; i < -x; i++) cout << "EW";
		}	
		if (y > 0) {
			for (int i = 0; i < y; i++) cout << "SN";
		}
		if (y < 0) {
			for (int i = 0; i < -y; i++) cout << "NS";
		}	
		cout << "\n";
	}
	return 0;
}	
