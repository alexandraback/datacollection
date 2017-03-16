#include <iostream>

using namespace std;

int main() {
	int T; cin >> T;
	
	for(int t = 1; t <= T; t++){
		int R, C, W; cin >> R >> C >> W;
		int ans = (R * (C - 1))/W + W;
		cout << "Case #" << t << ": " << ans << endl;
	}
}