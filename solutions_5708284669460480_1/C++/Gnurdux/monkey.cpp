#include <iostream>
#include <iomanip>
using namespace std;

int keycounts[26];
int target[1000];
int jump[1000];

int main() {
	int T;
	cin >> T;

	cout << setprecision(10);

	for (int t = 1; t <= T; t++) {
		int K, L, S;
		cin >> K >> L >> S;

		for (int i = 0; i < 26; i++) keycounts[i] = 0;

		for (int i = 0; i < K; i++) {
			char c;
			cin >> c;
			keycounts[c-'A']++;
		}
		bool bad = false;
		double prob = 1;
		for (int i = 0; i < L; i++) {
			char c;
			cin >> c;
			target[i] = c-'A';
			if (!keycounts[target[i]]) bad = true;

			prob *= double(keycounts[target[i]]) / double(K);

			if (i > 0) {
				int z = jump[i-1];
				for (;;) {
					if (target[i] == target[z]) jump[i] = z+1;
					else if (z == 0) jump[i] = 0;
					else {
						z = jump[z-1];
						continue;
					}

					break;
				}
			} else {
				jump[i] = 0;
			}
		}

		if (bad) {
			cout << "Case #" << t << ": 0\n";
			continue;
		}

		int best = 1 + (S-L) / (L-jump[L-1]);
		cout << "Case #" << t << ": " << best-prob*(S-L+1) << '\n';
	}

	return 0;
}
