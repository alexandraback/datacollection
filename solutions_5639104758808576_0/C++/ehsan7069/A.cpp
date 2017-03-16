/*
 * By: Ehsan
 *
 * Contact info: ehsan7069[at]gmail[dot]com
 */

#include <iostream>
#include <string>

using namespace std;

string shyness;

int ans;

void input () {
	int s_max; cin >> s_max; // just ignore!
	cin >> shyness;
	return;
}

void solve () {
	ans = 0;
	int current = 0;
	for (unsigned int i = 0 ; i < shyness.length() ; i++)
		if (shyness[i] != '0') {
			if (ans < ((int)i) - current)
				ans = ((int)i) - current;
			current += shyness[i] - '0';
		}
	return;
}

void output (int t) {
	cout << "Case #" << t + 1 << ": " << ans << endl;
	return;
}


int main() {
	int T;
	cin >> T;
	for (int t = 0 ; t < T ; t++) {
		input();
		solve();
		output(t);
	}
	return 0;
}


