#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


size_t subsolve(size_t *motes, size_t a, size_t n) {
	size_t pos = 0;
	if (n == 0) return 0;
	while (pos < n and motes[pos] < a) {
		a += motes[pos];
		++pos;
	}
	if (pos == n) return 0;
	else if (a == 1) {
		return n;
	} else {
		return min(n-pos, 1+subsolve(motes+pos, a*2-1, n-pos));
	}
}

void solve() {
	size_t a,n;
	cin >> a >> n;
	size_t *motes = new size_t[n];
	for (size_t i = 0; i < n; ++i) {		
		cin >> motes[i];
	}
	sort(motes, motes+n);
	cout << subsolve(motes, a, n) << endl;
}

int main() {
	int t; cin >> t;
		
	for (int tt = 1; tt <= t; ++tt) {
		cout << "Case #" << tt << ": ";
		solve();
	}
}
