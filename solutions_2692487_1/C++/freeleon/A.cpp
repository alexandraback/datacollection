/* Problem A. Osmos */
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 105;
int st, n;
int a[MAXN];

int main() {
	int T;
	cin >> T;
	for (int run = 1; run <= T; run++) {
		cin >> st >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a, a + n);
		int ans = n, cnt = 0;
		bool can = true;
		for (int i = 0; i < n; ++i) {
			if (st > a[i]) {
				st += a[i];
			} else {
				ans = min(ans, cnt + n - i);
				if (st - 1 == 0) {
					can = false;
					break;
				}
				st += st - 1;
				i--;
				cnt++;
			}
		}
		if (can) 
			ans = min(ans, cnt);
		cout << "Case #" << run << ": " << ans << endl;
	}
	return 0;
}
