#include <iostream>

using namespace std;
int main() {
	int T,R,C,W;
	cin >> T;
	for (int cas=1;cas<=T;cas++) {
		cin >> R >> C >> W;
		cout << "Case #" << cas << ": " << ((R-1)*(C/W)+(C+W-1)/W+W-1) << endl;
	}
	return 0;
}
