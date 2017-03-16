#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		int number = 0;
		long long slowness[2];
		long long starting[2];
		for (int i = 0; i < N; i++) {
			int D, H, M;
			cin >> D >> H >> M;
			for (int j = 0; j < H; j++) {
				starting[number] = D;
				slowness[number] = M+j;
				number++;
			}
		}

		int ans = 1;
		if (number < 2) ans = 0;
		else {
			if (slowness[1] > slowness[0]) {
				long long temp = starting[1];
				starting[1] = starting[0];
				starting[0] = temp;
				temp = slowness[1];
				slowness[1] = slowness[0];
				slowness[0] = temp;
			}

			if ((360 + starting[0] - starting[1]) * slowness[1] > (360 - starting[0]) * (slowness[0] - slowness[1])) ans = 0;
		}

		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}
