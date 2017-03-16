#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N;
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d", &N);
        printf("Case #%d: ", t);
        if (N == 0) {
            printf("INSOMNIA\n");
        } else {
            int cnt = 0;
            bool visit[10], flag = false;
            memset(visit, false, sizeof(visit));
            for (int j = 1; ; ++j) {
                int num = N * j;
                while (num) {
                    int mod = num % 10;
                    if (!visit[mod]) {
                        visit[mod] = true;
                        if (++cnt == 10) {
                            flag = true;
                            break;
                        }
                    }
                    num /= 10;
                }
                if (flag) {
                    printf("%d\n", N * j);
                    break;
                }
            }
        }
    }
    return 0;
}
