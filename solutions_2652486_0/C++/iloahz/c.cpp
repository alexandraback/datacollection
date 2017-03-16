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

const int MAXK = 15;
const int INF = 1 << 29;
const long long MOD = 55566677ll;
const int dx[] = {-1, 0, 0, 1, 1, 1, -1, -1};
const int dy[] = {0, -1, 1, 0, 1, -1, -1, 1};

int r, n, m, k;
int f[256][126];
int tot;

void prep(){
}

void init(){
    if (scanf("%d%d%d%d", &r, &n, &m, &k) == EOF) exit(0);
}

vector<int> ji;

int calc(){
    int s = 0;
    for (int i = 0;i < n;i++){
        s *= m - 1;
        s += ji[i] - 2;
    }
    return s;
}

void gao(){
//    for (int i = 0;i < n;i++){
//        printf("%d ", ji[i]);
//    }
//    printf("\n");
    int t = calc();
//    printf("t = %d\n", t);
    for (int i = 0;i < (1 << n);i++){
        int s = 1;
        for (int j = 0;j < n;j++){
            if ((1 << j) & i){
                s *= ji[j];
            }
        }
        f[t][s] += 1;
    }
}

void dfs(int x){
    if (x >= n){
        gao();
        tot += 1;
        return;
    }
    for (int i = 2;i <= m;i++){
        ji.push_back(i);
        dfs(x + 1);
        ji.pop_back();
    }
}

void output(int x){
    for (int i = 0;i < n;i++){
        printf("%d", x % (m - 1) + 2);
        x /= m - 1;
    }
    printf("\n");
}

int a[MAXK];
int p[256];
void work(){
    tot = 0;
    ji.clear();
    dfs(0);
    for (int i = 0;i < r;i++){
        for (int j = 0;j < tot;j++){
            p[j] = 1;
        }
        for (int j = 0;j < k;j++){
            scanf("%d", &a[j]);
            for (int q = 0;q < tot;q++){
                p[q] *= f[q][a[j]];
            }
        }
//        for (int j = 0;j < tot;j++){
//            printf("%d ", p[j]);
//        }
//        printf("\n");
        int mx = 0;
        for (int j = 0;j < tot;j++){
            if (p[j] > p[mx]){
                mx = j;
            }
        }
        output(mx);
    }
}

int main(){
#ifdef LATTE
//    freopen("c.in", "r", stdin);
    freopen("C-small-1-attempt0.in", "r", stdin);
    freopen("C-small-1-attempt0.out", "w", stdout);
//    freopen("B-large.in", "r", stdin);
//    freopen("B-large.out", "w", stdout);
#endif
    int T, t = 0;
    prep();
    scanf("%d", &T);
    while (T--){
        init();
        printf("Case #%d:\n", ++t);
        work();
    }
    return 0;
}
