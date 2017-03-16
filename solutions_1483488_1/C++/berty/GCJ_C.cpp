#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[2000010], T, a, b;
int xx[10];

int main () {
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 0; i <= 2000000; ++i)
		if (i < 10)
			dp[i] = 1;
		else if (i < 100 && i >= 10)
			dp[i] = 10;
		else if (i < 1000 && i >= 100)
			dp[i] = 100;
		else if (i < 10000 && i >= 1000)
			dp[i] = 1000;
		else if (i < 100000 && i >= 10000)
			dp[i] = 10000;
		else if (i < 1000000 && i >= 100000)
			dp[i] = 100000;
		else
			dp[i] = 1000000;
			
	for (int i = 0; i < T; ++i) {
		scanf("%d%d", &a, &b);
		int ans = 0;
		for (int j = a; j <= b; ++j) {
			bool ok = true;
			int x = 10;
			memset(xx, 0, sizeof xx);
			int pos = 0;
			while (ok) {
				int hasil = j % x;
				int wow = (dp[j] / dp[x / 10]) * hasil + j / x;
				if (j < wow && wow <= b) {
					bool ada = false;
					for (int k = 0; k < pos; ++k)
						if (xx[k] == wow) {
							ada = true;
							break;
						}
					
					if (!ada) {
						ans++;
						xx[pos++] = wow;
					}
				}
				x *= 10;
				if (x > j) ok = false;
			}
		}
		printf("Case #%d: %d\n", i + 1, ans);
	}
}
