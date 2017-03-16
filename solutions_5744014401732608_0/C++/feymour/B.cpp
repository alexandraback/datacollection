#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t=0;t<T;++t) {
		long B,M;
		cin >> B >> M;
		long max_val;
		max_val = 1 << (B-2);
		if (max_val < M) {
			cout << "Case #" << t+1 << ": IMPOSSIBLE" << endl;
		} else {
			cout << "Case #" << t+1 << ": POSSIBLE" << endl;
			int result[50][50];
			for (int i=0;i<50;++i) {
				for (int j=0;j<50;++j) {
					result[i][j] = 0;
				}
			}
			for (int i=0;i<B;++i) {
				for (int j=i+1;j<B;++j) {
					result[i][j] = 1;
				}
			}
			long res = max_val - M;
			for (int i = 0; i< B;++i) {
				if (res & (1<<i)) {
					result[0][B-i-2] = 0;
				}
			}
			for (int i=0;i<B;++i) {
				for (int j=0;j<B;++j) {
					cout << result[i][j];
				}
				cout << endl;
			}
		}
	}
	return 0;
}
