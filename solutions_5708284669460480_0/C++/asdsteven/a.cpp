#include <cstdio>

int K, L, S;
char k[10], l[10], s[10];
double max;

double dfs(int x) {
    if (x == S) {
        double ret = 0;
        for (int i = 0; i + L <= S; i++)
            for (int j = 0; s[i + j] == l[j]; j++)
                if (j == L - 1) {
                    ret++;
                    break;
                }
        if (ret > max)
            max = ret;
        return ret;
    }
    double ret = 0;
    for (int i = 0; i < K; i++) {
        s[x] = k[i];
        ret += dfs(x + 1);
    }
    return ret;
}

double solve() {
    scanf("%d%d%d%s%s", &K, &L, &S, k, l);
    max = 0;
    double n = 1;
    for (int i = 0; i < S; i++)
        n *= K;
    double z = dfs(0) / n;
    return max - z;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        printf("Case #%d: %f\n", i, solve());
}
