#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main () {
	int t;
	scanf ("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		int n, m, k;
		scanf ("%d%d%d", &n, &m, &k);
		int ans = k;
		for (int i = 1; i <= n - 2; i++)
			for (int j = 1; j <= m - 2; j++) {
				int ins = i * j;
				int need = 2 * (i + j);
				if (ins + need < k)
					need = k - ins;
				ans = min(ans, need);
			}
		for (int a = 1; a <= n - 2; a++)
			for (int b = 1; b <= m - 2; b++)
				for (int x = 1; x < b; x++) {
					int ins = a * b - (b - x);
					int need = 2 * (a + b) - 1;
					if (ins + need < k) need = k - ins;
					ans = min(ans, need);
				}
		printf ("Case #%d: %d\n", tt + 1, ans);
	}
}

