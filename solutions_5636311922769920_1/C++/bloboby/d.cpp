#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

int req(int K, int C) {
	return ((K-1)/C) + 1;
}

void fractile() {
	int K, C, S;
	cin >> K >> C >> S;
	int r = req(K,C);
	
	if (S < r) {
		cout << " IMPOSSIBLE" << endl;
		return;
	}
	
	if (r == 1) {
		ll tile = 0;
		ll power = pow(K,C-1);
		for (ll dig=1; dig<K; dig++) {
			tile += (dig-1) * power;
			power /= K;
		}
		tile += K;
		cout << " " << tile << endl;
	}
	else {
		ll dig = 1;
		for (int i=0; i<r; i++) {
			ll tile = 0;
			ll power = pow(K,C-1);
			for (int j=0; j<C-1; j++) {
				tile += (dig-1) * power;
				if (dig < K) dig++;
				power /= K;
			}
			tile += dig;
			if (dig < K) dig++;
			cout << " " << tile;
		}
		cout << endl;
	}
	
	return;
}

int main() {
	int T;
	cin >> T;
	for (int i=0; i<T; i++) {
		cout << "Case #" << i+1 << ":";
		fractile();
	}
	return 0;
}