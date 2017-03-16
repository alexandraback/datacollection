#include <iostream>
#include <cmath>
using namespace std;

double c[3010][3010];

int main() {
	int T;
	cin >> T;
	for (int i = 0; i <= 3000; i++)
		c[i][0] = c[i][i] = 1;
	for (int i = 1; i <= 3000; i++)
		for (int j = 1; j < i; j++)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	for (int ca = 1; ca <= T; ca++) {
		cout << "Case #" << ca << ": ";
		int n, x, y;
		cin >> n >> x >> y;
		int cnt = 0;
		for (cnt = 0; cnt * (2 * cnt - 1) <= n; cnt++);
		cnt--;
		int r = n - cnt * (2 * cnt - 1);
		int req = (abs(x) + abs(y)) / 2 + 1;
		if (req <= cnt) {
			cout << "1.0" << endl;
			continue;
		}
		if (req > cnt + 1 || x == 0) {
			cout << "0.0" << endl;
			continue;
		}
		int h = y + 1;
		cnt++;
		if (r >= h + 2 * cnt - 2) {
			cout << "1.0" << endl;
			continue;
		}
		double ans = 0;
		for (int i = h; i <= r; i++)
			ans += c[r][i];
		while (r > 0) {
			ans /= 2.0;
			r--;
		}
		cout << ans << endl;
	}
	return 0;
}
