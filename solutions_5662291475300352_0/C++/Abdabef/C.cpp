#include<iostream>

using namespace std;

long long z, n, k, D[10], H[10], M[10];

int main() {
	cin >> z;
	for (int t = 1; t <= z; t++) {
		cin >> n;
		k = n;
		for (int i = 0; i < k; i++) {
			cin >> D[i] >> H[i] >> M[i];
			if (H[i] == 2) {
				n++;
				D[i + 1] = D[i];
				H[i] = 1;
				H[i + 1] = 1;
				M[i + 1] = M[i] + 1;
			}
		}
		if (n == 1) {
			cout << "Case #" << t << ": " << "0" << endl;
		}
		else {
			if (D[0] >= D[1]) {
				D[0] += 360;
				if (720 * M[0] + M[0] * D[0] >= 720 * M[1] + M[1] * D[1]) {
					cout << "Case #" << t << ": " << "1" << endl;
				}
				else {
					cout << "Case #" << t << ": " << "0" << endl;
				}
			}
			else {
				D[1] += 360;
				if (720 * M[0] + M[0] * D[0] <= 720 * M[1] + M[1] * D[1]) {
					cout << "Case #" << t << ": " << "1" << endl;
				}
				else {
					cout << "Case #" << t << ": " << "0" << endl;
				}
			}
		}
		for (int i = 0; i < 5; i++) {
			D[i] = 0;
			H[i] = 0;
			M[i] = 0;
		}
	}
}
