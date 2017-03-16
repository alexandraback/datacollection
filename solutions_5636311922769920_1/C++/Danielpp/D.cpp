#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve(int c, int K, int C, int S) {
	cout << "Case #" << c << ":";
	int needed = (K + C - 1) / C;
	if (needed > S) { cout << " IMPOSSIBLE" << endl; return; }
	vector<ll> pows = {1};
	for (int i=1; i<C; i++) pows.push_back(pows.back() * K);
	reverse(pows.begin(), pows.end());
	
	int ind = 1;
	for (int j=0; j < needed; j++) {
		ll tile = 0;
		for (int level=0; level < C; level++) { 
			tile += pows[level] * (min(ind++, K) - 1);
		}
		cout << ' ' << tile + 1;
	}
	cout << endl;
}

int main() {
	int T, K, C, S;
	cin >> T;
	for (int c = 1; c <= T; c++) {
		cin >> K >> C >> S;
		solve(c, K, C, S);
	}
}