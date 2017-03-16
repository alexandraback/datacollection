#include <bits/stdc++.h>

using namespace std;

#define WIN "GABRIEL\n"
#define LOSE "RICHARD\n"

int main() {
	//freopen("D-small-attempt2.in","r",stdin);
	//freopen("D-small-attempt2.out","w",stdout);
	int t;
	cin >> t;
	for (int cnt = 1; cnt <= t; cnt++) {
		cout << "Case #" << cnt << ": ";
		int x,r,c;
		cin >> x >> r >> c;
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
		if (x-2 >= c) {
			cout << LOSE;
			continue;
		}
		cout << WIN;
	}
	return 0;
}
