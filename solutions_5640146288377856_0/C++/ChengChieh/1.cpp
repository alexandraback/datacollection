#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int T, r, c, w;

int main() {
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
	cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> r >> c >> w;

		int ans = c/w * r + w;
		if (c % w == 0) ans --;
		cout << "Case #" << test << ": " << ans << endl; 
	}
	return 0;
}
