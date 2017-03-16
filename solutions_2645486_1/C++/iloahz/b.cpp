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

const int MAXN = 10005;
const int INF = 1 << 29;
const long long MOD = 55566677ll;
const int dx[] = {-1, 0, 0, 1, 1, 1, -1, -1};
const int dy[] = {0, -1, 1, 0, 1, -1, -1, 1};

int n;
long long e, r;
long long a[MAXN];

void prep(){
}

void init(){
    if (scanf("%lld%lld%d", &e, &r, &n) == EOF) exit(0);
    for (int i = 0;i < n;i++) scanf("%lld", &a[i]);
}

int b[MAXN];

int findR(int x, long long y){
    if (x >= n || a[x] >= y) return x;
    return findR(b[x], y);
}

void work(){
    for (int i = n - 1;i >= 0;i--){
        b[i] = findR(i + 1, a[i]);
    }
    long long ans = 0;
    long long cur = e;
    for (int i = 0;i < n;i++){
//        printf("b[i] = %d\n", b[i]);
        long long t = min(cur, cur + r * (b[i] - i) - e);
        if (b[i] >= n) t = cur;
        t = max(t, 0ll);
//        printf("t = %lld\n", t);
        ans += t * a[i];
        cur -= t;
        cur += r;
    }
    printf("%lld\n", ans);
}

int main(){
#ifdef LATTE
//    freopen("b.in", "r", stdin);
//    freopen("B-small-attempt1.in", "r", stdin);
//    freopen("B-small-attempt2.out", "w", stdout);
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
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
