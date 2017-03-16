#include <bits/stdc++.h>
using namespace std;

typedef long long lint;

const int MAXC = 110;

int K, C, S;
lint pot[MAXC];

lint go(int idx, int level, lint cur) {
    cur += pot[level] * idx;
    if (level) return go(min(idx + 1, K - 1), level - 1, cur);
    else return cur;
}

int main() {
    int t = 1, T;
    for (scanf("%d", &T); t <= T; t++) {
        printf("Case #%d:", t);
        scanf("%d%d%d", &K, &C, &S);
        int needs = (K + C - 1) / C;
        if (needs > S) {
            printf(" IMPOSSIBLE\n");
            continue;
        }
        pot[0] = 1;
        for (int i = 1; i < MAXC; i++)
            pot[i] = K * pot[i-1];
        int cur = 0;
        while (cur < K) {
            printf(" %lld", go(cur, C - 1, 1));
            cur += C;
        }
        printf("\n");
    }
    return 0;
}
