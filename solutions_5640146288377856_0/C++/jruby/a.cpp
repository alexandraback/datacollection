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

    if (C == W) {
      cout << W << endl;
    } else {
      int cnt = 0;
      while (C > W) {
        C -= W;
        cnt++;
      }
      if (C == W) {
        cout << cnt + W << endl;
      } else {
        cout << cnt + W << endl;
      }
    }
	}
	return 0;
}
