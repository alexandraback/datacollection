#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	freopen("/home/ahmed/Desktop/A-large.in", "r", stdin);
	freopen("/home/ahmed/Desktop/A-large.out", "w", stdout);
	int t; scanf("%d", &t);
	int id = 1;
	while (t--) {
		int n; scanf("%d", &n);
		printf("Case #%d: ", id++);
		if (n == 0) {
			puts("INSOMNIA");
			continue;
		}
		int msk = 0, cur = n, ans = 0;
		while (msk < (1 << 10) - 1) {
			int ncur = cur + n;
			while (cur) {
				msk |= 1 << (cur % 10);
				cur /= 10;
			}
			cur = ncur;
			ans++;
		}
		printf("%d\n", cur - n);
	}
	return 0;
}
