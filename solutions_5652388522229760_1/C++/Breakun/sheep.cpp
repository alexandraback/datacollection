#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";

		long long N;
		cin >> N;

		if (N == 0) {
			cout << "INSOMNIA" << endl;
		} else {
			bool chk[10] = {false};
			int chk_cnt = 0; 
			long long i = 0LL;
			while (chk_cnt < 10) {
				i++;

				long long n = N * i;
				while (n) {
					if (!chk[n % 10LL]) {
						chk[n % 10LL] = true;
						chk_cnt++;
					}
					n /= 10LL;
				}
			}

			cout << N * i << endl;
		}
	}

	return 0;
}
