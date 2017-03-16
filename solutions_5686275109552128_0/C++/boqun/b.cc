#include <iostream>

using namespace std;

int P[2000];


int main()
{
	int T, D;
	cin >> T;
	for (int n = 1; n <= T; n++) {
		int time = 0;
		int m;
		int split = 0;
		int index = 0;
		int i = 0;
		cin >> D;
		for (; i < D; i++) {
			cin >> P[i];
			if (time < P[i]) {
				time = P[i];
				index = i;
			}
		}

		m = time;

		while (++split < m) {
			int tmp = P[index];
			int eat = 0;
			P[index] = tmp / 2;
			P[i++] = (tmp + 1) / 2;

			for (int j = 0; j < i; j++) {
				if (eat < P[j]) {
					eat = P[j];
					index = j;
				}
			}
			time = min(time, eat+split);
		}

		cout << "Case #" << n << ": " << time << endl;

	}
	return 0;
}
