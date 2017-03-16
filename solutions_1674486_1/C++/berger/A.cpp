#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>

int connect[1000][10];
int m[1000];
int n;
int seen[1000];

int dfs(int where) {
    if (seen[where]) {
        return 1;
    }
    seen[where] = 1;
    int i;
    for (i = 0; i < m[where]; i++)
    if (dfs(connect[where][i])) {
            return 1;
    }
    return 0;
}

int main() {
    int TT, T;
    scanf("%d", &TT);
    for (T = 1; T <= TT; T++) {
        scanf("%d", &n);
        
        int i, j;
        for (i = 0; i < n; i++) {
            scanf("%d", &m[i]);
            for (j = 0; j < m[i]; j++) {
                scanf("%d", &connect[i][j]);
                connect[i][j]--;
            }
        }
        
        int diamond = 0;
        
        for (i = 0; i < n && !diamond; i++) {
            for (j = 0; j < n; j++)
                seen[j] = 0;
            diamond+=dfs(i);
        }
            
        printf("Case #%d: %s\n", T, diamond? "Yes" : "No");
        
    }
}
        