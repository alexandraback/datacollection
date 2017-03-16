#include <iostream>
using namespace std;

int n, a[1010];

int split(int m) {
	int cnt = 0;
	for (int i = 0; i < n; i ++)
		cnt += ((a[i] + m - 1) / m - 1);
	return cnt;
}

int solve() {
	cin >> n;
	int h = 0, ans = 0x3f3f3f3f;
	for (int i = 0; i < n; i ++)
		cin >> a[i], h = max(h, a[i]);
	for (int i = 1; i <= h; i ++) 
		ans = min(ans, i + split(i));
	return ans;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i ++)
		cout << "Case #" << i << ": " << solve() << endl;
	return 0;
}
