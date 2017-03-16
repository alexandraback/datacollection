#include <stdio.h>
#include <string.h>

int n;
int c[2501];

int main()
{
    int dat;
    scanf("%d", &dat);
    for (int cas = 1; cas <= dat; ++cas) {
        scanf("%d", &n);
        memset(c, 0, sizeof(c));
        for (int i = 0; i < 2 * n - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                int h;
                scanf("%d", &h);
                ++c[h];
            }
        }
        printf("Case #%d:", cas);
        for (int i = 1; i <= 2500; ++i) {
            if (c[i]&1) printf(" %d", i);
        }
        puts("");
    }
}
