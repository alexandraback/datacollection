#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int a[200], n, s, p;

int main() {
	int t;
	scanf("%d", &t);
	for(int q=1; q<=t; ++q) {
		scanf("%d%d%d", &n, &s, &p);
		for(int i=0; i<n; ++i) scanf("%d", &a[i]);
		printf("Case #%d: ", q);

		sort(a, a + n);
		int ans = 0;
		for(int i=n-1; i>=0; --i) {
			int x = a[i] % 3;
			if(a[i] == 0) {
				if(p == 0) ans++;
			}
			else {

				if(a[i] / 3 + int((a[i] % 3 > 0)) >= p) {
					ans++;
				}
				else {

					if(x == 0) {
						if(s && a[i] / 3 + 1 >= p) {
							ans++;
							s--;
						}
					}
					else if(x == 2) {
						if(s && a[i] / 3 + 2 >= p) {
							ans++;
							s--;
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

