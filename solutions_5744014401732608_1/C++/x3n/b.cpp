#include <cmath>
#include <cinttypes>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXB = 50;
bool adj[MAXB][MAXB];

int64_t dfs_check(int b, int v)
{
    if (v == b - 1)
        return 1;

    int64_t res = 0;
    for (int i = 0; i < b; i++) {
        if (adj[v][i])
            res += dfs_check(b, i);
    }

    return res;
}

void solve(int64_t b, int64_t m)
{
    if (m > (1LL << (b - 2))) {
        puts("IMPOSSIBLE");
        return;
    }

    memset(adj, false, MAXB * MAXB);

    for (int i = 0; i < b - 2; i++) {
        for (int j = i + 1; j <= b - 2; j++) {
            adj[i][j] = true;
        }
    }

    m--;
    adj[0][b-1] = true;

    for (int i = 1; i < b - 1 && m > 0; i++) {
        adj[i][b-1] = m & 1;
        m >>= 1;
    }

    puts("POSSIBLE");

    for (int i = 0; i < b; i++) {
        for (int j = 0; j < b; j++) {
            printf("%d", adj[i][j]);
        }
        puts("");
    }

    //printf("Number of paths: %lld\n", dfs_check(b, 0));
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        int64_t b, m;
        scanf("%lld %lld", &b, &m);
        //printf("%lld %lld\n", b, m);
        printf("Case #%d: ", i);
        solve(b, m);
    }

    return 0;
}
