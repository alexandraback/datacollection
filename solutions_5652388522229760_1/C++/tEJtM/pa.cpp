#include<cstring>
#include<cstdio>
int main() {
	int tests;
	scanf("%d", &tests);
	for(int qq(1); qq <= tests; qq++) {
		int x;
		scanf("%d", &x);
		if(x == 0) {
			printf("Case #%d: INSOMNIA\n", qq);
			continue;
		}
		int x0(x);
		int cnt[10] = {};
		int tot(0);
		for(;;) {
			int y(x);
			while(y) {
				if(cnt[y % 10] == 0) {
					cnt[y % 10] = 1;
					tot++;
					if(tot == 10) {
						break;
					}
				}
				y /= 10;
			}
			if(tot == 10) {
				break;
			}else {
				x += x0;
			}
		}
		printf("Case #%d: %d\n", qq, x);
	}
}
