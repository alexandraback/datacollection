
#include <iostream>

using namespace std;

long reverse(long x) {
	long res = 0;
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
					//cout << "REVERT: " << i << endl;
					//cout << ", reached in " << steps[i];
				}
			}
		}
		//cout << endl;
	}
}


long orderhalf(long x) {
	long order = 10;
	while (x >= 100) {
		order *= 10;
		x /= 100;
	}
	return order;
}

long stepsdown(long from) {
	if (from < MAX) {
		//cout << "cached: " << from << endl;
		return steps[from];
	}
	if (from % 10 == 0) {
		//cout << "helper: " << from << endl;
		return stepsdown(from-1) + 1;
	}

	long o = orderhalf(from);
	//cout << "orderhalf for " << from << " is " << o << endl;
	long revpoint = (from / o) * o + 1;
	long rev = reverse(revpoint);
	if (rev < revpoint) {
		//cout << "from " << from << " via " << revpoint << endl;
		return (from - revpoint) + stepsdown(rev) + 1;
	} else {
		long next = revpoint - 2;
		//cout << "from " << from << " via " << next << endl;
		return (from - next) + stepsdown(next);
	}
}

int main() {
	precompute();

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		long x;
		cin >> x;
		cout << "Case #" << t << ": " << stepsdown(x) << endl;
	}

	return 0;
}
