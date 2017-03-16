
#include <iostream>

using namespace std;



int reverse(int x) {
	int res = 0;
	while (x > 0) {
		res = 10 * res + x % 10;
		x /= 10;
	}
	return res;
}

const int MAX = 1000001;
int steps[MAX];

void precompute() {
	steps[0] = 0;
	for (int i = 1; i < MAX; i++) {
		steps[i] = steps[i-1] + 1;
		//cout << i << " direct: " << steps[i];
		if (i % 10 != 0) {
			int revnum = reverse(i);
			//cout << ", reverse = " << revnum;
			if (revnum < i) {
				if (steps[revnum] + 1 < steps[i]) {
					steps[i] = steps[revnum] + 1;
					//cout << ", reached in " << steps[i];
				}
			}
		}
		//cout << endl;
	}
}


int main() {
	precompute();

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int x;
		cin >> x;
		cout << "Case #" << t << ": " << steps[x] << endl;
	}

	return 0;
}
