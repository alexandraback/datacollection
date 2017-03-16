#include <iostream>
using namespace std;
int T, R, C, W;

long long solve() {
	cin >> R >> C >> W;
	long long ans = C / W * (R - 1);
	long long r = (C / W);
	if (C % W == 0) {
		ans += r + W - 1;
	} else {
		ans += r + W;
	}
	return ans;
}

int main() {
    
    cin >> T;
    for (int t = 1; t <= T; ++t) {
    	cout << "Case #" << t << ": ";
    	cout << solve();
    	cout << "\n";
    }
	return 0;
}