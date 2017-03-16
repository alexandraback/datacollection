#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int T, B;
long long M;
int p[50];

int main() {

	cin >> T;

	for (int t = 1; t <= T; t++) {

		cin >> B >> M;
		printf("Case #%d:", t);

		memset(p, 0, 50);
		long long max = 1;
		max = max << (B - 2);
		if (M > max)
			cout << " IMPOSSIBLE\n";
		else {

			if (M == 0) {
				p[0] = 0;
			}
			else {
				p[0] = 1;
				M--;
				for (int i = 1; i < 50; i++) {  // assuming a 32 bit int
					p[i] = M & ((long long)1 << (i - 1)) ? 1 : 0;
				}
			}
			

			cout << " POSSIBLE" << endl;
			for (int i = 0; i < B; i++) {
				for (int j = 0; j <= i; j++)
					cout << 0;
				for (int j = i + 1; j < B - 1; j++)
					cout << 1;
				if (i != B - 1)
					cout << p[i];
				cout << "\n";
			}
		}
	}
}