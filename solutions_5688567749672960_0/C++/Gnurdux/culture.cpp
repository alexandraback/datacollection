#include <iostream>
using namespace std;

int best[1000001];

int main() {
	int T;
	cin >> T;

	best[1] = 1;
	for (int i = 1; i < 1000000; i++) {
		if (best[i+1] == 0 || best[i]+1 < best[i+1]) best[i+1] = best[i]+1;

		int reversed = 0;
		int cur = i;
		while (cur > 0) {
			reversed = reversed * 10 + (cur%10);
			cur /= 10;
		}
		if (reversed <= 1000000 && (best[reversed] == 0 || best[i]+1 < best[reversed])) best[reversed] = best[i]+1;
	}

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;
		cout << "Case #" << t << ": " << best[N] << '\n';
	}

	return 0;
}
