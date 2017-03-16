#include<iostream>
using namespace std;
int main() {
	int t, r, c, w, ans;
	cin >> t;
	for(int j = 1; j <= t; j++) {
		cin >> r >> c >> w;
		ans = (c/w)*r + (w - 1) + (c%w > 0);
		cout << "Case #" << j <<": " << ans << "\n";
	}
	return 0;
}
