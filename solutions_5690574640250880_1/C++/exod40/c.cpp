#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, k;
int dp[64][64 * 64][64];
int a[64][64];

void read() {
    scanf("%d%d%d", &n, &m, &k);
}

int go(int cols, int left, int mx) {
    if (left < 0) return 0;
    if (cols < 0) return 0;
    if (mx <= 1) return 0;
    if (!left) return 1;
    
    int &ans = dp[cols][left][mx];
    if (ans != -1) return ans;
    
    ans = 0;
    if (go(cols - 1, left - mx, mx)) return ans = 1;
    if (go(cols, left, mx - 1)) return ans = 1;
    
    return ans;
}

void prnt(int cols, int left, int mx) {
    if (!left) return ;
    
//    printf ("%d %d %d\n", cols, left, mx);
    
    if (go(cols - 1, left - mx, mx)) {
        for (int i = n - 1; i >= n - mx; i --) {
            a[i][cols - 1] = 1;
        }
        prnt (cols - 1, left - mx, mx);
    } else {
        prnt (cols, left, mx - 1);
    }
}

void solve() {
    if (n == 1 || m == 1) {
        for (int i = 0; i < max (n, m); i++) {
            if (i < k) {
                printf ("*");
            } else {
                if (i + 1 == max(n, m)) {
                    printf ("c");
                } else {
                    printf (".");
                }
            }
            
            if (m == 1) printf ("\n");
        }
        if (n == 1) printf ("\n");
        return ;
    }
    
    memset (a, 0, sizeof a);
    memset(dp, -1, sizeof dp);
    int left = n * m - k;
    int fnd = -1;
    for (int i = 2; i <= n; i++) {
        if (go(m - 2, left - 2 * i, i)) {
            fnd = i;
        }
    }
    
    if (left == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i + 1 == n && j + 1 == m) printf ("c");
                else printf ("*");
            }
            printf ("\n");
        }
        return ;
    }
    
    if (fnd == -1) {
        printf ("Impossible\n");
    } else {
        prnt(m - 2, left - 2 * fnd, fnd);
        for (int i = n - 1; i >= n - fnd; i--) {
            a[i][m - 2] = a[i][m - 1] = 1;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) printf ("*");
                else {
                    if (i + 1 == n && j + 1 == m) printf ("c");
                    else printf (".");
                }
            }
            printf("\n");
        }
    }
}

int main() {
    int cases;
    
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++) {
        read();
        printf ("Case #%d:\n", i);
        solve();
    }
    
    return 0;
}
