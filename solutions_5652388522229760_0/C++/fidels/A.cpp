#include <iostream>
using namespace std;

int main() {
	int T, t, N, V, i, n;
	
	cin >> T;
	for (t=1; t<=T; t++) {
		cin >> N;

		cout << "Case #" << t << ": ";
		if (N == 0) cout << "INSOMNIA" << endl;
		else {
			V = 0;
			for (i=N; ; i+=N) {
				n = i;
				while (n) {
					V |= (1<<(n%10));
					n /= 10;
				}
				if (V == (1<<10)-1) break;
			}
			cout << i << endl;
		}
	}

	return 0;
}
