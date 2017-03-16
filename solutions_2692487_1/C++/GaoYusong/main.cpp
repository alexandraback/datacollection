#include <cstdio>
#include <algorithm>

using namespace std;

int aa[110];

int main()
{
	int T;
	int cn = 0;

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	scanf("%d", &T);

	while (T--) {
		int n;
		int A;
		scanf("%d%d", &A, &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &aa[i]);
		}


		sort(aa, aa + n);

		int ans = n;
		for (int i = 0; i <= n; i++) {
			bool ok = false;
			for (int j = 0; j <= i; j++) {
				int opt1 = j, opt2 = i - j;
				int curr = A;
				bool ff = true;
				for (int k = 0; k < n - opt2; ) {
					if (curr > aa[k]) {
						curr += aa[k];
						k++;
					} else {
						curr += curr - 1;
						if (opt1 == 0) {
							ff = false;
							break;
						}
						opt1--;
					}
				}
				if (ff) {
					ok = true;
					break;
				}
			}
			if (ok) {
				ans = i;
				break;
			}
		}
		printf("Case #%d: %d\n", ++cn, ans);

	}
	return 0;
}
