#include <iostream>

using namespace std;

int T;
int x, y;

int main(){
	cin >> T;
	for (int caseNum = 0; caseNum < T; ++caseNum) {
		cin >> x >> y;
		cout << "Case #" << caseNum + 1 << ": ";
		for (int i = 0; i < abs(x); ++i) {
			cout << ((x < 0) ? "EW" : "WE");
		}
		for (int i = 0; i < abs(y); ++i) {
			cout << ((y < 0) ? "NS" : "SN");
		}
		cout << endl;
	}
}