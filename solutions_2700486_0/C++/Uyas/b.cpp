#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;

const int maxn = 1010101;
int level[maxn], sum[maxn], NN;
double f[777][777];

int dp__(int m) {
    f[0][0] = 1;
    f[1][0] = 0.5;
    f[0][1] = 0.5;
    for (int i = 1; i < m; ++i)
    for (int j = 1; j < m; ++j) {
        f[i][j] = 0;
        if (i == m - 1 && j == m - 1) f[i][j] = f[i][j - 1] + f[i - 1][j]; else
        if (j == m - 1) f[i][j] = f[i - 1][j] + f[i][j - 1] * 0.5; else
        if (i == m - 1) f[i][j] = f[i][j - 1] + f[i - 1][j] * 0.5; else
            f[i][j] = (f[i - 1][j] + f[i][j - 1]) * 0.5;
    }
}

int dp(int m){

    for (int i = 0; i <= m; ++i)
        for (int j = 0 ; j <= m; ++j) f[i][j] = 0;
    f[0][0] = 1;
    for (int i = 0; i < m; ++i)
    for (int j = 0 ; j < m; ++j) {
        if (i == m - 1 || j == m - 1) {
        if (i == m - 1) f[i][j + 1] += f[i][j];
        if (j == m - 1) f[i + 1][j] += f[i][j];
        } else {
        f[i][j + 1] += f[i][j] * 0.5;
        f[i + 1][j] += f[i][j] * 0.5;
        }
    }
    for (int i = 0; i <= m; ++i) f[i][m] = f[m][i] = 0;
}

double solve(int n, int x, int y) {
    if ((x + y + 1000000) % 2 == 1) return 0;
    int rem = n, l = 1;
    while (rem > level[l]) {
        rem -= level[l];
        l++;
    }

    if (x < 0) x = -x;
    int l1 = (x + y) / 2 + 1;
    //printf("%d %d %d %d %d\n", n, rem, l, l1, level[l]);
    if (l1 > l) return 0;
    if (l1 < l) return 1;
    if (rem == level[l]) return 1;
    int p = y + 1;
    int M = l * 2 - 1;
    dp(M);
    double ans = 0;
    for (int i = p; i < M && rem - i >= 0; ++i)
        ans += f[i][rem - i];
    return ans;
}

void work(int cas) {
    printf("Case #%d: ", cas);
    int r1, r2, r3;
    scanf("%d%d%d", &r1, &r2, &r3);
    double ans = solve(r1, r2, r3);
    printf("%.10f\n", ans);
//    checkPosition();
}

int main() {
    freopen("b1.in", "r", stdin);
    freopen("b1.out", "w", stdout);
    for (int i = 1; i < maxn; ++i) {
        level[i] = (i * 2 - 1) * 2 - 1;
        sum[i] = level[i] + sum[i - 1];
        NN = i;
       // printf("%d\n", sum[i]);
        if (sum[i] > maxn) break;
    }
  //  printf("%d\n", NN);
    //return 0;

    int t; scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
        work(i);
    return 0;
}
