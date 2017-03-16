#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 1005

int n;
int has[MAXN];

struct node {
    int one, two;

    bool operator<(const node & a)const {
        if (two != a.two)return two > a.two;
        else return one < a.one;
    }
} data[MAXN];

int main() {
    freopen("largein", "r", stdin);
    freopen("largeout", "w", stdout);
    int T;
    int cas = 1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        memset(has, false, sizeof (has));
        for (int i = 0; i < n; i++)
            scanf("%d%d", &data[i].one, &data[i].two);
        int nowstar = 0;
        int ans = 0;
        std::sort(data, data + n);
        //        for (int i = 0; i < n; i++)
        //            printf("%d %d\n", data[i].one, data[i].two);
        while (true) {
            int i;
            for (i = 0; i < n; i++) {
                if (nowstar >= data[i].two && has[i] == 0) {
                    break;
                }
            }
            if (i != n) {
                nowstar += 2;
                has[i] = 2;
                ans++;
                //// printf("%d:%d\n", ans, i);
                continue;
            }
            for (i = 0; i < n; i++) {
                if (nowstar >= data[i].two && has[i] == 1)
                    break;
            }
            if (i != n) {
                nowstar += 1;
                has[i] += 1;
                ans++;
                // printf("%d:%d\n", ans, i);
                continue;
            }
            for (i = 0; i < n; i++) {
                if (nowstar >= data[i].one && has[i] == 0)
                    break;
            }
            if (i != n) {
                nowstar += 1;
                has[i] += 1;
                ans++;
                // printf("%d:%d\n", ans, i);
                continue;
            }

            break;
        }
        printf("Case #%d: ", cas++);
        if (nowstar == n * 2)
            printf("%d\n", ans);
        else puts("Too Bad");
    }
}