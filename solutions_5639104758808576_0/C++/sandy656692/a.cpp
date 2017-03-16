#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

char s[1010];

int main() {
	int T;
	scanf("%d", &T);
	for (int ttt = 1; ttt <= T; ++ttt) {
		int maxs;
		scanf("%d%s", &maxs, s);
		int l = -1, r = 1010;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			int now = 0;
			bool flag = true;
			for (int i = 0; i < strlen(s); ++i) {
				if (now < i) {
					flag = false;
					break;
				}
				now += s[i] - '0';
				if (i == 0) now += mid;
			}
			if (flag) r = mid;
			else l = mid;
		}
		printf("Case #%d: %d\n", ttt, r);
	}
	return 0;
}