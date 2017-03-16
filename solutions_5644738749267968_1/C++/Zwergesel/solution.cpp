#include <iostream>
#include <algorithm>

using namespace std;

double a[1000], b[1000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int casenum=1; casenum<=t; casenum++) {
		cout << "Case #" << casenum << ": ";
		int n;
		cin >> n;
		for (int i=0; i<n; i++) cin >> a[i];
		for (int i=0; i<n; i++) cin >> b[i];
		sort(a, a+n);
		sort(b, b+n);
		int i(0), j(0), s(0);
		// Normal war (s = Ken's score)
		for (; i<n; i++) {
			while (j < n && b[j] < a[i]) j++;
			if (j < n) {
				s++;
				j++;
			}
		}
		// Deceptive war (d = Naomi's score)
		int lo(0), d(0);
		for (int i=0; i<n; i++) {
			if (a[i] > b[lo]) {
				d++;
				lo++;
			}
		}
		cout << d << " " << (n-s) << " ";
		cout << "\n";
	}
	return 0;
}