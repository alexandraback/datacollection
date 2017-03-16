#include <bits/stdc++.h>
using namespace std;

int T, N;

int main() {
	cin >> T;
	for (int t=1; t<=T; t++) {
		cin >> N;
		cout << "Case #" << t << ": ";
		if (N == 0) {
			cout << "INSOMNIA" << endl;
		} else {
			int ans=0, digits=0;
			do {
				ans += N;
				for (int x=ans; x; x/=10) digits |= 1<<(x%10);
			} while (digits != 1023);
			cout << ans << endl;
		}
	}
}
