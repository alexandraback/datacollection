#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t=1;t<=T;t++) {
		cout << "Case #" << t << ": ";
    int R, C, W;
    cin >> R;
    cin >> C;
    cin >> W;

    int cnt = 0;
    int CC = C;
    while (CC >= W) {
      CC -= W;
      cnt++;
    }
    int cnt2 = 0;
    CC = C;
    while (CC > W) {
      CC -= W;
      cnt2++;
    }
    int ans = (cnt) * (R-1) + cnt2;
    cout << ans + W << endl;
	}
	return 0;
}
