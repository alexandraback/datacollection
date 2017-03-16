#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int T; cin >> T;
	
	for(int t = 1; t <= T; t++){
		int R, C, W; cin >> R >> C >> W;
		int ans = 0;
		
		if(C == W) ans = R + W - 1;
		else if(W == 1) ans = R * C;
		else {
			ans = (R * (C - 1))/W + W;
			//ans = ceil((R * double(C))/W) + W - 1;
		}
		
		cout << "Case #" << t << ": " << ans << endl;
	}
}