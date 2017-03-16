#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; t++) {
		int R, C, W;
		cin >> R >> C >> W;
		int res = 0;
		res += C / W * R - (C % W ? 0 : 1);
		res += min(W, C);
		cout << "Case #" << t + 1 << ": " << res << endl;
	}
}
