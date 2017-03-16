// Google Code Jam 2015 Qualification Round C
// Dijkstra

#include <cstdio>

const int LEN = 1e4 + 2;

int T, L, X;
int S[LEN];

// i->2, j->3, k->4
const int table[5][5] = {
    {0,  0,  0,  0,  0},
    {0, -1,  2,  3,  4},
    {0,  2, -1,  4, -3},
    {0,  3, -4, -1,  2},
    {0,  4,  3, -2, -1},
};

int abs(int x) { return x > 0 ? x : -x; }
int calc(int lhs, int rhs) {
    int neg = 1;
    if (lhs < 0) neg *= -1;
    if (rhs < 0) neg *= -1;
    return neg * table[abs(lhs)][abs(rhs)];
}

int getijk() {
    char ch = getchar();
    while (ch < 'i' || ch > 'k') ch = getchar();
    return ch - 'i' + 2;
}

bool check_all() {
    int all = 1;
    for (int i = 0; i < X; i++)
        for (int j = 0; j < L; j++)
            all = calc(all, S[j]);
    return all == -1;
}

bool check_pre_suf() {
    int pre = 1, idx_pre = -1;
    for (int i = 0; i < X * L; i++) {
        pre = calc(pre, S[i % L]);
        if (pre == 2) {
            idx_pre = i;
            break;
        }
    }
    if (idx_pre == -1) return false;

    int suf = 1, idx_suf = -1;
    for (int i = X * L - 1; i >= 0; i--) {
        suf = calc(S[i % L], suf);
        if (suf == 4) {
            idx_suf = i;
            break;
        }
    }
    if (idx_suf == -1) return false;

    return idx_pre < idx_suf;
}

int main() {
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d%d", &L, &X);
        for (int i = 0; i < L; i++)
            S[i] = getijk();
        printf("Case #%d: %s\n", cas, check_all() && check_pre_suf() ? "YES" : "NO");
    }

    return 0;
}
