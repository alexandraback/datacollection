#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int sum[110], n, s, p;

int main() {
	int tc;
	cin >> tc;
	int res = 0;
	for (int tt = 1; tt <= tc; tt++) {
		cin >> n >> s >> p;
		res = 0;
		for (int i = 0; i < n; i++) {
			cin >> sum[i];
			int ms;
			if (sum[i] % 3 == 0) {
				ms = sum[i] / 3;
			} else {
				ms = sum[i] / 3 + 1;
			}
			if (ms >= p)
				res++;
			else if (s > 0) {
				if (sum[i] > 0 && sum[i] % 3 == 0 && sum[i] / 3 + 1 >= p) {
					res++; s--;
				} else if (sum[i] % 3 == 2 && sum[i] / 3 + 2 >= p) {
					res++; s--;
				}
			}
		}
		printf("Case #%d: %d\n", tt, res);
	}
}

