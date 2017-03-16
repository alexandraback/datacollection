#include <cstdio>
#include <cstring>

const int MAXN = 1000 + 1;

int T;
int n;

int a[MAXN], b[MAXN];
int mark[MAXN];

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);

    scanf("%d", &T);
    for (int c = 1; c <= T; c ++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) scanf("%d%d", &a[i], &b[i]);
        int cntStar = 0, round = 0;
        memset(mark, 0, sizeof(mark));
        bool win;
        while (true) {
            win = true;
            for (int i = 1; i <= n; i ++)
                if (mark[i] < 2) {
                    win = false;
                    break;
                }
            if (win) {
                printf("Case #%d: %d\n", c, round);
                break;
            }

            bool change = false;
            for (int i = 1; i <= n; i ++)
                if (mark[i] < 2 && b[i] <= cntStar) {
                    if (mark[i] == 1) cntStar += 1;
                    else cntStar += 2;
                    mark[i] = 2;
                    change = true;
                    round ++;
                }

            if (!change) {
                int max = 0, maxi = 0;
                for (int i = 1; i <= n; i ++)
                    if (mark[i] < 1 && a[i] <= cntStar) {
                        if (max < b[i]) {
                            max = b[i];
                            maxi = i;
                        }
                    }
                if (maxi > 0) {
                    mark[maxi] = 1;
                    cntStar ++;
                    change = true;
                    round ++;
                }
            }

            if (!change) break;
        }

        if (!win) printf("Case #%d: Too Bad\n", c);
    }
    
    return 0;
}

