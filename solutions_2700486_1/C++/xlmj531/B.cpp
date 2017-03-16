#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1500;

double f[maxn][maxn];

int N, X, Y;
int T;

void calc(int m ) {
     memset(f, 0, sizeof(f));
     f[0][0] = 1;
     for (int i = 0; i <= m; i++ )
         for (int j = 0; j <= m; j++ ) {
             if (i > 0) f[i][j] += f[i-1][j] * (j==m ? 1 : 0.5);
             if (j > 0) f[i][j] += f[i][j-1] * (i==m ? 1 : 0.5);
         }
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    scanf("%d",&T);
    for (int cas = 1; cas <= T; cas++ ) {
        scanf("%d%d%d",&N,&X,&Y);
        X = abs(X);
        int lvl, num;
        for (lvl = 1, num = 1; ; ++lvl, num+=4)
            if (num > N) break; else N -= num;
        int D = (X+Y)/2;
        printf("Case #%d: ",cas);
        if (D < lvl-1) printf("1.0\n");
        else if (D > lvl-1) printf("0.0\n");
        else if (X == 0) printf("0.0\n");
        else {
             int m = lvl*2-2;
             calc(m);
             double ans = 0;
             for (int i = m+1-X; i<=m; i++ )
                 if (i <= N && N-i <= m) ans += f[i][N-i];
             printf("%lf\n",ans);
        }
    }
    return 0;
}
