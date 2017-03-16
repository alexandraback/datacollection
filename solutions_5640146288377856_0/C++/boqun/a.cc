#include <iostream>

using namespace std;

int main()
{
	int T;
	int R, C, W;
	cin >> T;
	for (int n = 1; n <= T; n++) {
		cin >> R >> C >> W;

		cout << "Case #" << n << ": " << (C - 1) / W + W << endl;
	}
	return 0;
}
