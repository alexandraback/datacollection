#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1005;
int a[maxn], b[maxn];
int worked[maxn];
int test, testi, n;

void work() {
    int i;
    memset(worked, 0, sizeof worked);
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
        scanf("%d%d", a + i, b + i);
    int sum = 0, sb = 0, ans = 0;
    while (sb <= n) {
        bool flag = false;
        for (i = 1; i <= n; ++i)
            if (worked[i] < 2 && sum >= b[i]) {
                if (worked[i] == 1) sum += 1; else sum += 2;
                worked[i] = 2, ++sb, ++ans, flag = true;
                break;
            }
        if (flag) continue;
        int tmp = -1, maxa = -1;
        for (i = 1; i <= n; ++i)
            if (worked[i] == 0 && sum >= a[i]) {
                flag = true;
                if (b[i] >= maxa)
                    tmp = i, maxa = b[i];
            }
        if (tmp == -1) break;
        else {
            worked[tmp] = 1; ++sum; ++ans;
        }
    }
    printf("Case #%d: ", testi);
    if (sb < n) printf("Too Bad\n");
    else printf("%d\n", ans);
}           

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    scanf("%d", &test);
    for (testi = 1; testi <= test; ++testi)
        work();
    fclose(stdout);
    return 0;
}
