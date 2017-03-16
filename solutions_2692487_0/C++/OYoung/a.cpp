#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int ca, n, m, ans, tmp, now;
int a[200];

int main()
{
	freopen("a.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> ca;
	for (int t = 1; t <= ca; t++) {
		cin >> m >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		ans = n;
		if (m > 1) {
			for (int i = 0; i < n; i++) {
				tmp = n - 1 - i; now = m;
				for (int j = 0; j <= i; j++) {
					while (now <= a[j]) {now += now - 1; ++tmp;}
					now += a[j];
				}
				ans = min(ans, tmp);
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}

