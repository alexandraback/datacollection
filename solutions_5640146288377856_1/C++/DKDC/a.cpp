#include <iostream>

using namespace std;

int main(void)
{
	int T, n = 1;
	int R, C, W;

	cin >> T;
	while (n <= T) {
		cout << "Case #" << n++ << ": ";
		cin >> R >> C >> W;
		int answer = (R - 1) * (C / W) + C / W + W - 1;
		if (C % W >  0) {
			answer++;
		}
		cout << answer << endl;
	}

	return 0;
}
