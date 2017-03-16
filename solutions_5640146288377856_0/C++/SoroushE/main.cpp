#include <iostream>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	for (int o = 1; o <= tt; o++) {
		int r, c, w;
		cin >> r >> c >> w;
		int ans = -1;
		if (w == c)
			ans = r + w - 1;
		else if (w * 2 > c)
			ans = r + w;
		else {
			if (c % w == 0)
				ans = (int)(c / w) * r + w - 1;
			else
				ans = (int)(c / w) * r + w;
		}
		cout << "Case #" << o << ": " << ans << endl;
	}
	return 0;
}
