#include <bits/stdc++.h>

using namespace std;

#define WIN "GABRIEL\n"
#define LOSE "RICHARD\n"

int main() {
	freopen("D-large.in","r",stdin);
	freopen("D-large.out","w",stdout);
	int t;
	cin >> t;
	for (int cnt = 1; cnt <= t; cnt++) {
		cout << "Case #" << cnt << ": ";
		int x,r,c;
		cin >> x >> r >> c;
		if (x >= 7) {
			cout << LOSE;
			continue;
		}
		if (c > r)
			swap(r,c);
		if (x > r) {
			cout << LOSE;
			continue;
		}
		if ((r*c)%x != 0) {
			cout << LOSE;
			continue;
		}
		if (x/2.0 > c) {
			cout << LOSE;
			continue;
		}
		if (x == 4) {
			if (c <= 2) {
				cout << LOSE;
				continue;
			}
		}
		if (x == 6) {
			if (c <= 4) {
				cout << LOSE;
				continue;
			}
		}
		cout << WIN;
	}
	return 0;
}
