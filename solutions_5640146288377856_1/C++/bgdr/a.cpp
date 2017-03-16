#include<iostream>
using namespace std;
int main() {
	int T, R, C, W;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cin >> R >> C >> W;
		int res = (C / W) * R  - 1 + (C % W != 0) + W;
		cout << "Case #" << t << ": " << res << endl;
	}
	return 0;
}