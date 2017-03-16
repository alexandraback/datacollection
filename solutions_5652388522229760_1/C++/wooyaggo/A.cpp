#include <stdio.h>
#include <string.h>

typedef long long ll;

int main(void) {
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		printf("Case #%d: ", tc);
		ll N; scanf("%I64d", &N);
		
		if (N == 0) {
			printf("INSOMNIA\n");
			continue;
		}

		bool exist[10];
		memset(exist, false, sizeof(exist));
		int cnt = 0;
		long long y = 0;
		int j = 0;
		while (cnt != 10) {
			y += N;
			char ch[22]; sprintf(ch, "%I64d", y);
			int len = strlen(ch);
			for (int i = 0; i < len; i++) {
				int idx = ch[i]-'0';
				if (!exist[idx]) { 
					exist[idx] = true;
					cnt ++;
				}
			}
		}
		printf("%I64d\n", y);	
	}

	return 0;
}