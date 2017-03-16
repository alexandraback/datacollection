#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10000000
int buf[105];
int a, n;
int main(void) {
	int t;
	cin >> t;
	for (int ti=1; ti<=t; ++ti) {
		cin >> a >> n;
		for (int i=0; i<n; ++i) {
			cin >> buf[i];
		}
		sort(buf, buf+n);
		int ans = n;
		int step = 0;
		for (int i=0; i<n; ++i) {
			if (a == 1) {
				break;
			}
			if (a <= buf[i]) {
				if (step+n-i < ans) {
					ans = step + n - i;
				}
				do {
					a = a*2 -1;
					++step;
				} while (a<=buf[i]);
				a += buf[i];
			} else {
				if (a<MAX) {
					a += buf[i];
				}
			}
		}
		if (a !=1) {
			if (step < ans) {
				ans = step;
			}
			cout << "Case #" << ti << ": " << ans << endl;
		} else {
			cout << "Case #" << ti << ": " << n << endl;
		}
	}
	return 0;
}