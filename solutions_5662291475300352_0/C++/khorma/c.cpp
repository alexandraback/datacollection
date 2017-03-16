//In the name of God
//...
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double LD;

int h[2], d[2], n;

int main() {
	int test = 0;
	cin >> test;
	for (int tt = 1; tt <= test; tt++) {
		int cnt = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> d[cnt] >> x >> h[cnt];
			cnt++;
			if (x == 2) {
				d[cnt] = d[cnt - 1];
				h[cnt] = h[cnt - 1] + 1;
			}
		}
//		cerr << d[0] << ' ' << h[0] << '\n';
//		cerr << d[1] << ' ' << h[1] << '\n';
		cout << "Case #" << tt << ": ";
		if (cnt < 2)
			cout << 0 << '\n';
		else {
			if (d[0] > d[1]) {
				swap(d[0], d[1]);
				swap(h[0], h[1]);
			}
			bool flag = false;
			{
				int t1 = (360 - d[0]) * h[0]; // : * 1/360
				if (t1 >= h[1] * ((360 - d[1]) + 360))
					flag = true;
			}
			{
				int t = (360 - d[1]) * h[1]; // * 1/360
				if (t >= h[0] * ((360 - d[0]) + 360))
					flag = true;
			}
			cout << flag << '\n';
		}
	}
	return 0;
}
