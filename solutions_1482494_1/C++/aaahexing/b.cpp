#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int cas, n, sum, a[1010], b[1010], s[1010];

int main() {
	scanf("%d", &cas);
	for (int ca = 1; ca <= cas; ++ca) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			s[i] = 0;
			scanf("%d%d", &a[i], &b[i]);
		}
		sum = 0;
		int ans = 0;
		int rem = n;
		while (rem > 0) {
			bool add = false;
			for (int i = 0; i < n; ++i) {
				if (s[i] == 0 && sum >= b[i]) {
					add = true;
					sum += 2;
					s[i] = 2;
					--rem;
					++ans;
					break;
				}
			}
			if (add) continue;
			for (int i = 0; i < n; ++i) {
				if (s[i] == 1 && sum >= b[i]) {
					add = true;
					sum += 1;
					s[i] = 2;
					--rem;
					++ans;
					break;
				}
			}
			if (add) continue;
			int bi = -1;
			for (int i = 0; i < n; ++i) {
				if (s[i] == 0 && sum >= a[i]) {
					if (bi == -1 || b[i] > b[bi]) {
						bi = i;
					}
				}
			}
			if (bi >= 0) {
				add = true;
				sum ++;
				s[bi] = 1;
				++ans;
			}
			if (!add) break;
		}
		printf("Case #%d: ", ca);
		if (rem > 0)
			printf("Too Bad\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
