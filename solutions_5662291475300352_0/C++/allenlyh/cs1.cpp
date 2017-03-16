#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

typedef long long LL;
int n;
struct Tpo {
	int pos;
	int v;
}po[5];
int cnt;

int main() {
	int T;
	int cas = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		printf("Case #%d: ", ++cas);
		cnt = 0;
		for (int i=0;i<n;i++) {
			int pos, h, m;
			scanf("%d%d%d", &pos, &h, &m);
			for (int j=0;j<h;j++, m++) {
				po[cnt].pos = pos;
				po[cnt].v = m;
				cnt++;
			}
		}
		if (cnt == 1) {
			puts("0");
		} else if (po[0].v == po[1].v) {
			puts("0");
		} else {
			if (po[0].v < po[1].v) {
				swap(po[0], po[1]);
			}
			int tmp = 360 + po[0].pos - po[1].pos;
			if (LL(360 - po[0].pos) * (po[0].v - po[1].v) >= LL(tmp) * po[1].v) {
				puts("1");
			} else {
				puts("0");
			}
		}
	}
	return 0;
}
