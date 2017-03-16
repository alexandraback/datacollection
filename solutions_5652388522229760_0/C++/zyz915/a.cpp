#include <cstring>
#include <cstdio>
#include <cstdlib>

const int N = 30;
int big[N], num[N], occ[N];
char buf[N];

void run(int cas) {
    int n;
    scanf("%s", buf);
    sscanf(buf, "%d", &n);
    if (n == 0) {
        printf("Case #%d: INSOMNIA\n", cas);
        return;
    }
    int l = strlen(buf), ll = l, i;
    for (i = 0; i < l; i++)
        num[l - i - 1] = buf[i] - '0';
    memset(big, 0, sizeof(big));
    memset(occ, 0, sizeof(occ));
    while (true) {
        for (i = 0; i < l; i++)
            big[i] += num[i];
        for (i = 0; i < ll; i++)
            if (big[i] > 9) {
                big[i] -= 10;
                big[i + 1]++;
            }
        if (big[ll]) ll++;
        int flag = 1;
        for (i = 0; i < ll; i++)
            occ[big[i]] = 1;
        for (i = 0; i < 10; i++)
            flag = flag & occ[i];
        if (flag) break;
    }
    memset(buf, 0, sizeof(buf));
    for (i = 0; i < ll; i++)
        buf[ll - i - 1] = big[i] + '0';
    printf("Case #%d: %s\n", cas, buf);
}

int main() {
    int tt;
    scanf("%d", &tt);
    for (int cas = 1; cas <= tt; cas++)
        run(cas);
}

