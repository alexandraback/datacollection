#include <stdio.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n, bit[20];
string a[20], b[20];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, runs = 0; for (scanf("%d", &T); T--; ) {
		++runs;
		printf("Case #%d: ", runs);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
		}
		int res = 0;
		for (int i = 0; i < (1 << n); i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (((1 << j)&i) == (1 << j)) bit[j] = 1, cnt++;
				else bit[j] = 0;
			}
			int ok = 1;
			for (int j = 0; j < n; j++) {
				if (bit[j]) {
					int r = 0;
					for (int k = 0; k < n; k++) {
						if (!bit[k]) {
							if (a[j] == a[k]) r |= 1;
							if (b[j] == b[k]) r |= 2;
						}
					}
					if (r != 3) {
						ok = 0;
						break;
					}
				}
			}
			if (ok) res = max(res, cnt);
		}
		printf("%d\n", res);
	}
	fcloseall();
	return 0;
}