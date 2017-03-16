/*
 * By: Ehsan
 *
 * Contact info: ehsan7069[at]gmail[dot]com
 */

#include <iostream>

using namespace std;

int my_ceil (int x, int y) {
	return (x + y - 1) / y;
}

const int MAX_n = 10 * 1000, MAX_p = 1000 + 1;

int d, p[MAX_n], ans;

void input () {
	cin >> d;
	for (int i = 0 ; i < d ; i++)
		cin >> p[i];
	return;
}

void solve () {
	ans = -1;
	for (int i = 1 ; i < MAX_p ; i++) {
		int current = i;
		for (int j = 0 ; j < d ; j++)
			current += my_ceil(p[j], i) - 1;
		if (ans == -1 || ans > current)
			ans = current;
	}
	return;
}

void output (int t) {
	cout << "Case #" << (t + 1) << ": " << ans << endl;
	return;
}


int main () {
	int T;
	cin >> T;
	for (int t = 0 ; t < T ; t++) {
		input();
		solve();
		output(t);
	}
	return 0;
}


