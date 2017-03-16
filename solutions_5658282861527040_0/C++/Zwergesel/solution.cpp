#include <iostream>

using namespace std;

void solve() {
	int a, b, k;
	cin >> a >> b >> k;
	long long cc = 0;
	for (int i=0; i<a; i++) {
		for (int j=0; j<b; j++) {
			if ((i & j) < k) cc++;
		}
	}
	cout << cc;
}

int main() {
	int t;
	cin >> t;
	for (int casenum=1; casenum<=t; casenum++) {
		cout << "Case #" << casenum << ": ";
		solve();
		cout << "\n";
	}
	return 0;
}