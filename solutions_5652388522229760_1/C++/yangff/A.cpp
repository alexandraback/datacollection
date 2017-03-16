#include <cstdio>
#include <cstring>

bool cnt[10];

int main(){
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int T; scanf("%d",  &T);
	for (int i = 1; i <= T; i++){
		int n; scanf("%d", &n);
		if (n == 0) {
			printf("Case #%d: INSOMNIA\n", i);
			continue; 
		}
		memset(cnt, 0, sizeof(cnt));
		int counts = 10;
		for (long long j = 1; ;j++) {
			long long a = (long long)j * (long long)n;
			while (a && counts) { if (!cnt[a % 10]) {cnt[a%10] = true; counts--; } a /= 10; }
			if (counts == 0) {
				printf("Case #%d: %lld\n", i, (long long)j * (long long)n);
				break;
			}
		}
	}
}