#include <stdio.h>

int T;
int n;
int total;
int ans;
char num[1100];

int main()
{
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d%s", &n, num);
        total = 0;
        ans = 0;
        for (int j = 0; j <= n; j++) {
            if (total < j) {
                ans += j - total;
                total = j;
            }
            total += num[j] - '0';
        }
        printf("Case #%d: %d\n", i, ans);
    }

	return 0;
}

