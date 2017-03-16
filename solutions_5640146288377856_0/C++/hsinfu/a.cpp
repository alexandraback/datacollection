#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring> // memset(void *b, int c, size_t len);
#include <algorithm> // sort
#include <iomanip> // cout << std::fixed << std::setprecision(4)

using namespace std;

int main(int argc, char* argv[]) {
	int T, R, C ,W;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		cin >> R >> C >> W;
		int yesR = W + ((C-1)/W);
		int notR = C/W;
		int ans = yesR + notR*(R-1);
		cout << "Case #" << t+1 << ": " << ans << endl;
	}
	return 0;
}

