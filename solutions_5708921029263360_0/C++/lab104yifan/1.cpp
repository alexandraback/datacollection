#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 105;

int J, P, S, K;

struct SB {
    int a, b, c;
    SB() {}
    SB(int a, int b, int c) : a(a), b(b), c(c) {}
} sb[N];
int sn;

int cnt[10][10][10];
int tot;

int bitcount(int x) {
    int cnt = 0;
    while (x) {
        if (x&1) cnt++;
        x >>= 1;
    }
    return cnt;
}

int Max, ans;

void dfs(int u, int s) {
    if (u == sn) {
        int tmp = bitcount(s);
        if (Max < tmp) {
            Max = tmp;
            ans = s;
        }
        return;
    }
    int a = sb[u].a, b = sb[u].b, c = sb[u].c;
    cnt[a][b][0]++;
    cnt[a][0][c]++;
    cnt[0][b][c]++;
    int flag = 1;
    if (cnt[a][b][0] > K || cnt[a][0][c] > K || cnt[0][b][c] > K) flag = 0;
    if (flag) dfs(u + 1, s^(1<<u));
    cnt[a][b][0]--;
    cnt[a][0][c]--;
    cnt[0][b][c]--;
    dfs(u + 1, s);
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int T, cas = 0;
    scanf("%d", &T);
    while (T--) {
        sn = 0;
        scanf("%d%d%d%d", &J, &P, &S, &K);
        for (int i = 1; i <= J; i++) {
            for (int j = 1; j <= P; j++) {
                for (int k = 1; k <= S; k++) {
                    sb[sn++] = SB(i, j, k);
                }
            }
        }
        Max = 0;
        dfs(0, 0);
        printf("Case #%d: %d\n", ++cas, Max);
        for (int i = 0; i < sn; i++) {
            if (ans&(1<<i)) {
                printf("%d %d %d\n", sb[i].a, sb[i].b, sb[i].c);
            }
        }
    }
    return 0;
}
