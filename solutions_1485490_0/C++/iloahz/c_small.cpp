#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;

int n, m;
__int64 a[MAXN], A[MAXN];
__int64 b[MAXN], B[MAXN];
__int64 f[MAXN][MAXN];
__int64 g[MAXN][MAXN][2];
__int64 ans;

void dfs(int x1, __int64 y1, int x2, __int64 y2, __int64 z){
    //printf("%d %I64d %d %I64d %I64d\n", x1, y1, x2, y2, z);
    ans = max(ans, z);
    if (x1 > n || x2 > m){
        return;
    }
    if (A[x1] == B[x2]){
        __int64 t1 = a[x1] - y1 + 1ll;
        __int64 t2 = b[x2] - y2 + 1ll;
        if (t1 < t2){
            dfs(x1 + 1, 1ll, x2, y2 + t1, z + t1);
        }
        else{
            dfs(x1, y1 + t2, x2 + 1, 1ll, z + t2);
        }
    }
    else{
        dfs(x1 + 1, 1ll, x2, y2, z);
        dfs(x1, y1, x2 + 1, 1ll, z);
    }
}

int main(){
#ifdef ILOAHZ
    //freopen("c.in", "r", stdin);
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
//    freopen("A-small-attempt1.in", "r", stdin);
//    freopen("A-small-attempt1.out", "w", stdout);
//    freopen("A-large.in", "r", stdin);
  //  freopen("A-large.out", "w", stdout);
#endif
    int T, t = 0;
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n, &m);
        for (int i = 1;i <= n;i++) scanf("%I64d%I64d", &a[i], &A[i]);
        for (int i = 1;i <= m;i++) scanf("%I64d%I64d", &b[i], &B[i]);
        ans = 0;
        dfs(1, 1ll, 1, 1ll, 0ll);
        printf("Case #%d: %I64d\n", ++t, ans);
        //break;
    }
    return 0;
}
