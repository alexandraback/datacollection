#include <iostream>
using namespace std;

int main() {
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int t, c, r, w, ans;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		cin >> r >> c >> w;
		ans = (c / w) * (r - 1) ;
		ans += ((c - 1) / w) + w ;
		cout << "Case #" << i << ": " << ans << endl;
	}
	return 0;
}