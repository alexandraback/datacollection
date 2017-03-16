#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

void doit(int casenum) {
	int X, Y;
	cin >> X >> Y;
	
	string xs, ys;
	xs = (X >= 0) ? "WE" : "EW";
	ys = (Y >= 0) ? "SN" : "NS";
	
	cout << "Case #" << casenum << ": ";
	
	for (int i = 0; i < abs(X); ++i) {
		cout << xs;
	}
	for (int i = 0; i < abs(Y); ++i) {
		cout << ys;
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	cin.get();
	for (int i = 1; i <= t; ++i) doit(i);
	return 0;
}