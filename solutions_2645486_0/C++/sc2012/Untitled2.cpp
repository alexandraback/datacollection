#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int f[20][20];
int v[20];
int min(int a, int b){
    if (a < b) return a;
    return b;
}
int main() {
    int T, tt;
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("out2.txt", "w", stdout);
    scanf("%d", &T);
    for (tt = 0; tt < T; ++tt) {
        int E,R,N;
        scanf("%d%d%d", &E, &R, &N);
        for (int i = 0; i < N; ++i)
            scanf("%d", v+i+1);
        memset(f, -1, sizeof(f));
        f[0][E] = 0;
        int ans = 0;
        for (int i = 1; i <= N; ++i)
            for(int j = 0; j <= E; ++j)
                if (f[i-1][j] >= 0) {
                    for (int k = 0; k <= j; ++k){
                        if (f[i][min(E,j-k+R)] < f[i-1][j]+v[i]*k)
                            f[i][min(E,j-k+R)] = f[i-1][j]+v[i]*k;
                    }
                }
        for (int i = 0; i <= E; ++i)
            if(ans < f[N][i])ans = f[N][i];
        printf("Case #%d: %d\n", tt+1, ans);
    }
}
