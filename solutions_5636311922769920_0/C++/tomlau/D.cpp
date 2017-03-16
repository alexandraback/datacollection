#include <bits/stdc++.h>
using namespace std;

long long t, i, T, K, C, S, KC;

int main() {
	cin >> T;
	for (t=1; t<=T; t++) {
		cin >> K >> C >> S;
		KC = K;
		for (i=1; i<C; i++) KC *= K;
		cout << "Case #" << t << ": ";
		if (K == S) {
			for (long long i=1; i<=KC; i+= KC/K)
				cout << i << " ";
		} else {
			cout << "IMPOSSIBLE";
		}
		cout << endl;
	}
}
