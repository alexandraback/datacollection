#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <string>
using namespace std;


int main() {
#ifdef _DEBUG
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);
#endif

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int R, C, W;
		cin >> R >> C >> W;
		int result = ((C + (W - 1)) / W + W - 1) * R;
		cout << "Case #" << t << ": " << result << endl;
	}

	return 0;
}
