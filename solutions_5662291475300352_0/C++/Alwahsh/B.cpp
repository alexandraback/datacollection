#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define var double

ll start[2],num[2],speed[2];

int t;

int main() {
	ios::sync_with_stdio(0);
	freopen("C-small-1-attempt1.in","r",stdin);
	freopen("a2.out","w",stdout);
	cin >> t;
	for (int cntt = 1; cntt <= t; cntt++) {
		cout << "Case #" << cntt << ": ";
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> start[i] >> num[i] >> speed[i];
		}
		if (n == 1)
			cout << 0;
		else {
			ll faster = (speed[0] < speed[1])? 0:1;
			ll slower = (faster == 0)? 1:0;
			var tFaster = (var)(720-start[faster]) * speed[faster] / 360.0;
			var tSlower = (var)(360 - start[slower]) * speed[slower] / 360.0;
			if (tFaster > tSlower) {
				cout << 0;
			} else {
				cout << 1;
			}
		}
		cout << endl;
	}

	return 0;
}
