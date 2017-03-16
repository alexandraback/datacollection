#include <cstdio>
int d[30],n,m;
bool done[30];
int dfs(int a) {
    done[a] = true;
    if (d[a]) return d[a];
    if (a%n == 0 || a%n == n-1 || a/n == 0 || a/n == m-1) return d[a]=-1;
    if (d[a-n]==-1 || ((!done[a-n]) && dfs(a-n) == -1)) return d[a] = -1;
    if (d[a-1]==-1 || ((!done[a-1]) && dfs(a-1) == -1)) return d[a] = -1;
    if (d[a+1]==-1 || ((!done[a+1]) && dfs(a+1) == -1)) return d[a] = -1;
    if (d[a+n]==-1 || ((!done[a+n]) && dfs(a+n) == -1)) return d[a] = -1;
    return d[a] = 1;
}
int main() {
    int T,k;
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        scanf("%d%d%d", &n,&m,&k);
        int ans = n*m;
        for (int i=0; i<(1<<(n*m)); i++) {
            int res = 0, num = 0;
            for (int j=0; j<n*m; j++) done[j] = false;
            for (int j=0; j<n*m; j++) num += (d[j] = bool(i&(1<<j)));
            for (int j=0; j<n*m; j++)
                if (dfs(j) == 1) res++;
            if (res >= k && num < ans) ans = num;
        }
        printf("Case #%d: %d\n", t,ans);
    }
    return 0;
}
