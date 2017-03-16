#include <iostream>
using namespace std;

int numpancakes[1000];

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int D;
		cin >> D;
		
		for (int i = 0; i < D; i++) {
			cin >> numpancakes[i];
		}

		int ans = 1000;
		for (int n = 1; n <= 1000; n++) {
			int poss = n;
			for (int i = 0; i < D; i++)
				poss += (numpancakes[i] + n-1)/n - 1;
			if (poss < ans) ans = poss;
		}
		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}
