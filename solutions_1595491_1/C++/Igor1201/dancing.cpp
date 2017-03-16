#include <iostream>

using namespace std;

int main () {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N, S, p, y = 0;
		cin >> N >> S >> p;
		int *enes = new int[N];
		for (int j = 0; j < N; j++) {
			cin >> enes[j];
			int aux = enes[j] % 3;
			enes[j] = enes[j] / 3;

			if (aux == 0) {
				if (enes[j] >= p) y++;
				else if (enes[j] > 0 && enes[j] + 1 >= p) { y++; S--; }
			}
			else if (aux == 1) {
				if (enes[j] + 1 >= p) y++;
			}
			else if (aux == 2) {
				if (enes[j] + 1 >= p) y++;
				else if (enes[j] + 2 >= p) { y++; S--; }
			}
		}
		if (S < 0) y += S;

		cout << "Case #" << t+1 << ": " << y << endl;

		delete [] enes;
	}

	return 0;
}