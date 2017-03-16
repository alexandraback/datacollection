#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int T, k, l, s, cnt, sum, ma;
char t[10], m[10], n[10];

int comp() {
    int ret = 0;
    for (int i = 0; i + l - 1 < s; i++) {
        if (n[0] == t[i]) {
            bool f = true;
            int j;
            for (j = 0; j < l; j++) {
                if (n[j] != t[j + i]) {
                    f = false;
                    break;
                }
            }
            if (f) ret++;
        }
    }
    return ret;
}

void dfs(int d) {
    if (d == s) {
        int num = comp();
        sum += num;
        ma = max(num, ma);
        cnt++;
        return;
    }
    for (int i = 0; i < k; i++) {
        t[d] = m[i];
        dfs(d + 1);
    }
}

int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        cnt = sum = ma = 0;
        scanf("%d%d%d", &k, &l, &s);
        scanf("%s", m);
        scanf("%s", n);

        dfs(0);
        printf("Case #%d: %.8f\n", i, (double) (ma * cnt - sum) / (double) cnt);
    }
    return 0;
}
