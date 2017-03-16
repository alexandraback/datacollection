#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		int X, Y;
		cin >> X >> Y;
		string ans;
		int x = 0, y = 0, s = 1;
		for (int d = X > x ? -1 : 1; x != X; s++, d = -d) {
			if (d > 0) {
				x += s;
				ans += 'E';
			} else {
				x -= s;
				ans += 'W';
			}
		}

		for (int d = Y > y ? -1 : 1; y != Y; s++, d = -d) {
			if (d > 0) {
				y += s;
				ans += 'N';
			} else {
				y -= s;
				ans += 'S';
			}
		}

		printf("Case #%d: %s\n", ti, ans.c_str());
	}
	return 0;
}
