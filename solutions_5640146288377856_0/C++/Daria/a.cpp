#include <fstream>
using namespace std;

int T, t, R, C, W;
int main() {
	ifstream fi("test.in");
	ofstream fo("test.out");
	fi >> t;
	for (int T = 1; T <= t; T++) {
		fi >> R >> C >> W;
		int x = (C/W) + (W-1) + ((C%W == 0) ? 0 : 1);
		fo << "Case #" << T << ": " << x*R << "\n";
	}
	return 0;
}