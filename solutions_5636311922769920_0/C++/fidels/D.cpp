#include <iostream>
using namespace std;

int main() {
	int T, t, K, C, S, i, j;
	long long cur, d;
	
	cin >> T;
	for (t=1; t<=T; t++) {
		cin >> K >> C >> S;
		
		cout << "Case #" << t << ":";
		if (S*C < K) cout << " IMPOSSIBLE" << endl;
		else {
			S = (K+C-1)/C;

			d = 0LL;
			for (i=0; i<S; i++) {
				cur = 0LL;
				for (j=0; j<C; j++) {
					cur = cur*K + d;
					d++; if (d == K) break;
				}
				cout << ' ' << cur+1;
			}
			cout << endl;
		}
	}

	return 0;
}
