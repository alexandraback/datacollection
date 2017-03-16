#include <cstdio>
#include <algorithm>

using namespace std;

int tc, n, s;
char a[111];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &tc);
	for (int tn = 0; tn < tc; tn++) {
		scanf("%d%d", &s, &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a+n);
		int k = 0;
		int res = 1<<30;
		if (s <= a[0] && s == 1)
			k = n;
		else
			for (int i = 0; i < n; i++) {
				if (s > a[i]) {
					s += a[i];
				} else {
					res = min(res, k+n-i);
					s += s-1;
					k++;
					i--;
				}
			}
		printf("Case #%d: %d\n", tn+1, min(res, k));
	}
	return 0;
}