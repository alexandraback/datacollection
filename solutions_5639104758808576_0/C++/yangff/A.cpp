#include <cstdio>

char buf[2222];

int main(){
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++){
		printf("Case #%d: ", i + 1);
		int s;
		scanf("%d", &s);
		scanf("%s", &buf);
		int claping = 0; int ans = 0;
		for (int j = 0; j < s; j++) {
			claping += buf[j] - '0';
			if (claping < j + 1) {
				ans += j + 1 - claping;
				claping = j + 1;
			}
		}
		printf("%d\n", ans);
	}
}