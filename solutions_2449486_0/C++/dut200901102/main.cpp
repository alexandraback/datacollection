#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 110;

int n, m;
int f[N][N];
int u[N][N], d[N][N], l[N][N], r[N][N];

void init(){
    scanf("%d %d", &n, &m);
    memset(u, 0, sizeof(u));
    memset(d, 0, sizeof(d));
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            scanf("%d", &f[i][j]);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            u[i][j] = max(u[i - 1][j], f[i][j]);
            l[i][j] = max(l[i][j - 1], f[i][j]);
        }
    for(int i = n; i >= 1; --i)
        for(int j = m; j >= 1; --j){
            d[i][j] = max(d[i + 1][j], f[i][j]);
            r[i][j] = max(r[i][j + 1], f[i][j]);
        }
}
bool solve(){
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if((u[i][j] > f[i][j] || d[i][j] > f[i][j]) 
                && (l[i][j] > f[i][j] || r[i][j] > f[i][j])) return false;
    return true;
}
int main(){
    int t, cas = 1;
    for(cin >> t; t--; ){
        printf("Case #%d: ", cas++);
        init();
        puts(solve() ? "YES" : "NO");
    }
    return 0;
}
