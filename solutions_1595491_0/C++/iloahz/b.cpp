#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;
const int MAXS = 105;
const int MAXP = 15;
const int MAXT = 35;

int n, s, p;
int sc[MAXN];
int f[MAXN][MAXS];
bool g[MAXT][2];

void init(){
    scanf("%d%d%d", &n, &s, &p);
    for (int i = 0;i < n;i++) scanf("%d", &sc[i]);
    memset(f, -1, sizeof(f));
    memset(g, 0, sizeof(g));
    for (int i = 0;i <= 10;i++)
        for (int j = i;j <= i + 2 && j <= 10;j++)
            for (int k = j;k <= i + 2 && k <= 10;k++)
                g[i + j + k][i + 2 == k] = k >= p;
}

int dp(int x, int y){
    f[0][0] = 0;
    for (int i = 0;i < n;i++)
        for (int j = 0;j <= i && j <= s;j++)
            if (f[i][j] >= 0){
                f[i + 1][j] = max(f[i + 1][j], f[i][j] + g[sc[i]][0]);
                if (j < s) f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + g[sc[i]][1]);
            }
    //printf("--------------%d\n", f[1][0]);
    return f[n][s];
}

int main(){
#ifdef ILOAHZ
    //freopen("b.in", "r", stdin);
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
#endif
    int T, t = 0;
    scanf("%d", &T);
    while (T--){
        init();
        printf("Case #%d: %d\n", ++t, dp(n, s));
    }
    return 0;
}
