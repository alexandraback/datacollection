#include <iostream>
#include <cmath>
using namespace std;

char ans[100000], ans1[100000];

int main()
{
	int t, x, y;
	cin >> t;
	for (int	 i = 1; i <= t; ++i) {
		cin >> x >> y;
		cout << "Case #" << i << ": ";
		int min(0), x1(x), y1(y), x2 = abs(x), y2 = abs(y);
		for (int k = 10*(sqrt(x2+y2)+1); k >= 0; --k) {
			int p = k*(k+1)/2-x2-y2;
			if (p < 0) break;
			if (p%2) continue;
			x = x1, y = y1;
			for (int j = k; j >= 1; --j) {
				if (abs(x) > abs(y)) {
					if (x >= 0) {
						x -= j;
						ans[j] = 'E';
					}
					else {
						x += j;
						ans[j] = 'W';
					}
				}
				else {
					if (y >= 0) {
						y -= j;
						ans[j] = 'N';
					}
					else {
						y += j;
						ans[j] = 'S';
					}
				}
			}
			if (x == 0 && y == 0) {
				min = k;
				for (int j = 1; j <= min; ++j)
					ans1[j] = ans[j];
			}
		}
		for (int j = 1; j <= min; ++j)
			cout << ans1[j];
		cout << '\n';
	}
	return 0;
}
