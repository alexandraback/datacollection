#include <iostream>
#include <vector>
using namespace std;

int testcases;

int main() {
	cin >> testcases;
	for (int testcase = 0; testcase < testcases; testcase ++) {
		int n, a, b;
		cin >> n >> a >> b;
		if (a < b) {
			int tmp = a; a = b; b = tmp;
		}
		bool o = false; 

		if (n <= 6) {
			if (n == 6) {
				o = (a >= 6) && (b >= 3) && ((a * b) % 6 == 0);
			} else if (n == 5) {
				o = (a >= 5) && (b >= 4) && ((a * b) % 5 == 0);
			} else if (n == 4) {
				o = (a >= 4) && (b >= 3) && ((a * b) % 4 == 0);
			} else if (n == 3) {
				o = (a >= 3) && (b >= 2) && ((a * b) % 3 == 0);
			} else if (n == 2) {
				o = (a >= 2) && (b >= 1) && ((a * b) % 2 == 0);
			} else if (n == 1) {
				o = true;
			}
		}

		cout << "Case #" << testcase + 1 << ": ";
		if (o) {
			cout << "GABRIEL";
		} else {
			cout << "RICHARD";
		}

		cout << endl;
	}

	return 0;
}