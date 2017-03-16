#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl

typedef long long ll;

int K, C, S;

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
		cin >> K >> C >> S;
		cout << "Case #" << icase << ":";
		
		if (S*C < K) {
			cout << " IMPOSSIBLE" << endl;
			continue;
		}
		
		for (int i = 0; i < S; i++) {
			// combine i*C, i*C+1, ... (has C terms)
			// stop when K-1 has been seen, and max out at that
			ll r = 0;
			ll p = 1;
			bool seen = 0;
			for (int j = 0; j < C; j++) {
				ll x = min(i*C + j, K-1);
				//TRACE(x);
				if (x == K-1) seen = 1;
				r += p*x;
				p *= K;
			}
			cout << " " << r+1;
			if (seen) {
				cout << endl;
				break;
			}
		}
	}
	return 0;
}
