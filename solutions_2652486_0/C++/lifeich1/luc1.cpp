#include<cstdio>
#include<algorithm>
#define bit(x) (1 << (x))
using namespace std;
int v[21],s[21],TT,n,m,R,K,f[bit(13)];
bool check() {
    for (int i = 0; i < bit(n); ++i) {
        f[i] = 1;
        for (int j = 0; j < n; ++j)
            if (i & bit(j)) f[i] *= s[j + 1];
    }
    for (int j,bl,i = 1; i <= K; ++i) {
        for (j = 0, bl = 0; !bl && j < bit(n); ++j) bl |= f[j] == v[i];
        if (!bl) return 0;
    }
    return 1;
}
bool dfs(int r, int l) {
    if (r > n) return check();
    for (int i = l; i <= m; ++i) {
        s[r] = i;
        if (dfs(r + 1, i)) return 1;
    }
    return 0;
}
int main() {
    scanf("%d", &TT);
    printf("Case #1:\n");
    scanf("%d%d%d%d", &R, &n, &m, &K);
    for (; R; --R) {
        for (int i = 1; i <= K; ++i) scanf("%d", v + i);
        dfs(1, 2); 
        for (int i = 1; i <= n; ++i) printf("%d", s[i]);
        puts("");
    }
    return 0;
}
