#include <bits/stdc++.h>
using namespace std;

void test(int TT) {
	long long n;
	long long m;
	cin >> n >> m;
	cout << "Case #" << TT << ": ";
	if(m > 1 << (n-2)) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	cout << "POSSIBLE" << endl;

	cout << "0";
	for(long long i=n-3; i>=0; i--) {
		if(m >= 1 << i) {
			cout << "1";
			m -= 1 << i;
		} else cout << "0";
	}
	cout << m << endl;

	for(int i=2; i<=n; i++) {
		cout << string(i, '0') << string(n-i, '1') << endl;
	}
}

int main() {
	int t;
	cin >> t;
	for(int i=1; i<=t; i++) test(i);
}
