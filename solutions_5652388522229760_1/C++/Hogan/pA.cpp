#include <cstdio>

void test() {
    int suc = 0;
    for (int i = 0; i <= 1000000; i++) {
        bool vis[10] = {0};
        int cnt = 0;
        for (int j = 1; j <= 75 and cnt < 10; j++) {
            int v = i * j;
            while (v) {
                if (vis[v%10] == false) {
                    vis[v%10] = true;
                    cnt += 1;
                }
                v /= 10;
            }
        }
        if (cnt == 10) {
            suc += 1;
        } else {
            printf("%d\n", i);
        }
    }
    printf("suc = %d\n", suc);
}

int main() {
    int T = 0, n;
    scanf("%d", &T);

    for (int times = 0; times < T; times++) {
        scanf("%d", &n);
        if (n == 0) {
            printf("Case #%d: INSOMNIA\n", times+1);
            continue;
        }

        bool vis[10] = {0};
        int cnt = 0;
        for (int i = 1; i <= 75; i++) {
            int v = n * i;
            while (v) {
                if (vis[v%10] == false) {
                    vis[v%10] = true;
                    cnt += 1;
                }
                v /= 10;
            }

            if (cnt == 10) {
                printf("Case #%d: %d\n", times+1, n * i);
                break;
            }
        }
    }
}
