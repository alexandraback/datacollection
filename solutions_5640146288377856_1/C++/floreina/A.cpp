#include <iostream>
#include <fstream>

using namespace std;

ifstream inf("A-large.in");
ofstream ouf("output.txt");
int main() {
	int T; inf >> T;
	for (int t = 1; t <= T; ++t) {
		int R, C, W;
		inf >> R >> C >> W;
		int ans = (R - 1) * (C / W);
		if (C % W == 0) {
			ans += (C / W) - 1 + W;
		}
		else {
			ans += (C / W) + W;
		}
		ouf << "Case #" << t << ": " << ans << endl;
	}
}