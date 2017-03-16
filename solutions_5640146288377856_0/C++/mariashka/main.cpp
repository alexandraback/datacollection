#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int t, c, r, w;
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> r >> c >> w;
		int ans = 0;
		if (c % w == 0) {
			ans = (c / w) * r + w - 1;
			ans = max(ans, (c / w - 1) * r + w);
		} else {
			ans = (c / w) * r + w;
		}
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
	return 0;
}
