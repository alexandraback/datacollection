#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 15;
const int INF = 1 << 29;
const long long MOD = 55566677ll;
const int dx[] = {-1, 0, 0, 1, 1, 1, -1, -1};
const int dy[] = {0, -1, 1, 0, 1, -1, -1, 1};

int e, r, n;
int a[MAXN];

void prep(){
}

void init(){
    if (scanf("%d%d%d", &e, &r, &n) == EOF) exit(0);
    for (int i = 0;i < n;i++) scanf("%d", &a[i]);
}

int f[MAXN][MAXN];
void work(){
    memset(f, -1, sizeof(f));
    f[0][e] = 0;
    for (int i = 0;i < n;i++){
        for (int j = 0;j <= e;j++){
            if (f[i][j] >= 0){
                for (int k = 0;k <= j;k++){
                    f[i + 1][min(e, j - k + r)] = max(f[i + 1][min(e, j - k + r)], f[i][j] + k * a[i]);
                }
            }
        }
    }
//    printf("%d\n", f[1][5]);
    printf("%d\n", f[n][min(r, e)]);
}

int main(){
#ifdef LATTE
//    freopen("b.in", "r", stdin);
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
//    freopen("A-large.in", "r", stdin);
//    freopen("A-large.out", "w", stdout);
#endif
    int T, t = 0;
    prep();
    scanf("%d", &T);
    while (T--){
        init();
        printf("Case #%d: ", ++t);
        work();
    }
    return 0;
}
