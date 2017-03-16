#include<iostream>

using namespace std;

int abs(int x) {
	return x > 0 ? x : -x;
}

int main() {
	int x, y, Ncase;
	
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> Ncase;
	for (int T = 1; T <= Ncase; T ++) {
		cout << "Case #" << T << ": ";
		
		cin >> x >> y;
		for (int i = 0; i < abs(x); i ++) {
			if (x > 0) {
				cout << "WE";
			} else {
				cout << "EW";
			}
		}
		
		for (int i = 0; i < abs(y); i ++) {
			if (y > 0) {
				cout << "SN";
			} else {
				cout << "NS";
			}
		}
		
		cout << endl;
	}
}
