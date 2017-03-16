#include <stdio.h>

int T;
int n;
int num[1100];
int max;
int ans;
int now;

int main()
{
    scanf("%d", &T);
    for (int z = 1; z <= T; z++) {
        scanf("%d", &n);
        max = 0;
        ans = 2147483647;
        for (int i = 0; i < n; i++) {
            scanf("%d", num + i);
            if (num[i] > max) {
                max = num[i];
            }
        }

        for (int i = 1; i <= max; i++) {
            now = i;
            for (int j = 0; j < n; j++) {
                if (i >= num[j]) {
                    continue;
                }
                if (num[j] % i) {
                    now++;
                }
                now += num[j] / i;
                now--;
            }
            if (now < ans) {
                ans = now;
            }
        }

        printf("Case #%d: %d\n", z, ans);
    }
	return 0;
}

