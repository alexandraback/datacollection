#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 25;
const int MAXS = 200005;

int n;
int a[MAXN];
int s[MAXN];
int f[MAXN][MAXS];

void printAns(int x, int y){
    if (f[x][y] > 0){
        printAns(f[x][y], y - a[x]);
        printf(" %d", a[x]);
    }
    else printf("%d", a[x]);
}

bool work(){
    s[0] = 0;
    for (int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
    memset(f, -1, sizeof(f));
    for (int i = 1;i <= n;i++){
        f[i][a[i]] = 0;
        for (int j = a[i];j <= s[i];j++)
            for (int k = 1;k < i;k++){
                if (f[k][a[i]] >= 0){
                    printAns(k, a[i]);
                    printf("\n");
                    printf("%d\n", a[i]);
                    return true;
                }
                if (f[k][j - a[i]] >= 0){
                    if (f[i][j] >= 0){
                        printAns(i, j);
                        printf("\n");
                        f[i][j] = k;
                        printAns(i, j);
                        printf("\n");
                        return true;
                    }
                    else{
                        f[i][j] = k;
                    }
                }
            }
    }
    return false;
}

int main(){
#ifdef ILOAHZ
    //freopen("c.in", "r", stdin);
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    //freopen("A-large.in", "r", stdin);
    //freopen("A-large.out", "w", stdout);
#endif
    int T, t = 0;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (int i = 1;i <= n;i++) scanf("%d", &a[i]);
        printf("Case #%d:\n", ++t);
        if (!work()) printf("Impossible\n");
    }
    return 0;
}
