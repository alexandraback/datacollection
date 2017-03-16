#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for(int loop = 1; loop <= T; loop++) {
		cout << "Case #" << loop << ": ";
		int b[50][50] = { 0 };

		ll B, M;
		cin >> B >> M;

		if(M != 1 && M > (1LL << (B - 2))) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}

		for(int i = 0; i < B - 1; i++) {
			for(int j = i + 1; j < B - 1; j++) {
				b[i][j] = 1;
			}
		}
		if(M == 1) {
			b[0][B - 1] = 1;
		}
		else if(M == 1LL << (B - 2)) {
			for(int i = 0; i < B - 1; i++) {
				b[i][B - 1] = 1;
			}
		}
		else {
			for(int i = 0; i < B - 1; i++) {
				if(M & (1LL << i)) {
					b[i + 1][B - 1] = 1;
				}
			}
		}

		cout << "POSSIBLE" << endl;
		for(int i = 0; i < B; i++) {
			for(int j = 0; j < B; j++) {
				cout << b[i][j];
			}
			cout << endl;
		}
	}

}