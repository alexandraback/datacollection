#include <iostream>

using namespace std;

int main() {
	int T;

	cin >> T;
	int index = 1;

	while(T--) {
		int ans = 0;

		int A,B,N;
		cin >> A >> B >> N;

		for (int i = 0 ; i < A ; ++i) {
			for (int j = 0 ; j < B ; ++j) {
				if ((i & j) < N) {
					ans++;
				}
			}
		}
		cout << "Case #" << index++ << ": " << ans << endl;
	}
}