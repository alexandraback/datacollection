#include <bits/stdc++.h>
#define MAXN 1123

using namespace std;

char st[MAXN], stAns[MAXN];
int isBig[MAXN];

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%s", st);
        int len = strlen(st);
        char maxC = 'A';
        for (int i = 0; i < len; ++i) {
            isBig[i] = 0;
        }
        for (int i = 0; i < len; ++i) {
            if (st[i] >= maxC) {
                maxC = st[i];
                isBig[i] = 1;
            }
        }
        stAns[len] = st[len];
        int l = 0, r = len - 1;
        for (int i = len - 1; i >= 0; --i) {
            if (isBig[i]) stAns[l++] = st[i];
            else stAns[r--] = st[i];
        }
        printf("Case #%d: %s\n", t, stAns);
    }
    return 0;
}