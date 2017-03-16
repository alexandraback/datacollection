#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	int T;
	cin.sync_with_stdio(false);
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		long long ans = -1;
		int D;
		cin >> D;
		int P[1000];
		for (int i = 0; i < D; i++) {
			cin >> P[i];
		}
		for (int i = 1; i <= 1000; i++) {
			long long tempans = 0;
			for (int j = 0; j < D; j++) {
				tempans += (P[j] - 1) / i;
			}
			tempans += i;
			if (ans == -1 || ans > tempans) {
				ans = tempans;
			}
		}
		cout << "Case #" << cas << ": " << ans << endl;
	}
}