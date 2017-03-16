#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
#define MP make_pair

const int MAXN = 20;
int ar[MAXN], N, sum;
int v1[MAXN], v2[MAXN];
bool vist[MAXN];

bool dfs2(int d, int p, int cs, int s, int d2) {
    if (cs == s) {
        for (int i = 0; i < d2; ++i) {
            if (i) putchar(' ');
            printf("%d", v1[i]);
        } puts("");
        for (int i = 0; i < d; ++i) {
            if (i) putchar(' ');
            printf("%d", v2[i]);
        } puts("");
        return true;
    }
    if (p == N) return false;
    if (vist[p]) return dfs2(d, p + 1, cs, s, d2);
    vist[p] = true; v2[d] = ar[p];
    if (dfs2(d + 1, p + 1, cs + ar[p], s, d2)) return true;
    vist[p] = false;
    if (dfs2(d, p + 1, cs, s, d2)) return true;
    return false;
}

bool dfs(int d, int p, int s) {
    if (2 * s > sum) return false;
    if (s && dfs2(0, 0, 0, s, d)) return true;
    if (p == N) return false;
    vist[p] = true;
    v1[d] = ar[p];
    if (dfs(d + 1, p + 1, s + ar[p])) return true;
    vist[p] = false;
    if (dfs(d, p + 1, s)) return true;
    return false;
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int nCase; scanf("%d", &nCase);
    for (int tCase = 1; tCase <= nCase; ++tCase) {
        scanf("%d", &N);
        sum = 0;
        for (int i = 0; i < N; ++i) {
            scanf("%d", &ar[i]);
            sum += ar[i];
        }
        printf("Case #%d:\n", tCase);
        bool flag = dfs(0, 0, 0);
        if (!flag) puts("Impossible");
    }
    return 0;
}