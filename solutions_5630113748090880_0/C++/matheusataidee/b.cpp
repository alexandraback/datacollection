#include <bits/stdc++.h>

using namespace std;

#define MAXN 10010

int v[MAXN];

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int z = 1; z <= t; z++) {
		int n;
		cin >> n;
		memset(v, 0, sizeof(v));
		for (int i = 0; i < 2 * n - 1; i++) {
			for (int j = 0; j < n; j++) {
				int x;
				cin >> x;
				v[x]++;
			}
		}
		cout << "Case #" << z << ":";
		for (int i = 1; i <= 2500; i++) {
			if (v[i] % 2 == 1) {
				cout << " " << i;
			}
		}
		cout << endl;
	}
	return 0;
}
