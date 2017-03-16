#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int n, m;
long long cache[101][101];
long long a[101];
int A[100];
long long b[101];
int B[100];

long long dp(int x, int y) {
    if (cache[x][y] != -1LL)
        return cache[x][y];
    if (x >= n)
        return 0LL;
    if (y >= m)
        return 0LL;
    long long ans = 0LL;
    int i, j;
    long long t = 0LL;
    if (A[x] == B[y]) {
        i = x;
        j = y;
        int type = A[x];
        long long ca = a[x];
        long long cb = b[y];
        while (i < n && j < m) {
            if (ca > cb) {
                t+=cb;
                ca-=cb;
                ans = max(ans, t + dp(i+1, j+1));
                j++;
                while (B[j] != type && j < m)
                    j++;
                cb = b[j];
            } else {
                t+=ca;
                cb-=ca;
                ans = max(ans, t + dp(i+1, j+1));
                i++;
                while (A[i] != type && i < n)
                    i++;
                ca = a[i];
            }
        }
    }
    ans = max(ans, dp(x+1, y));
    ans = max(ans, dp(x, y+1));
    cache[x][y] = ans;
    return ans;
}

int main() {
    int TT, T;
    scanf("%d", &TT);
    for (T = 1; T <= TT; T++) {
        
        scanf("%d%d", &n, &m);
        int i, j;
        for (i = 0; i < n; i++)
            scanf("%lld%d", &a[i], &A[i]);
        for (i = 0; i < m; i++)
            scanf("%lld%d", &b[i], &B[i]);
        for (i = 0; i <= n; i++)
            for (j = 0; j <= m; j++)
                cache[i][j] = -1LL;
        
        printf("Case #%d: %lld\n", T, dp(0, 0));
        
    }
}
        