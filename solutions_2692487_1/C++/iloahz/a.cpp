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

const int MAXN = 105;
const int INF = 1 << 29;
const long long MOD = 55566677ll;

int n, m;
int a[MAXN];

void prep(){
}

void init(){
    if (scanf("%d%d", &m, &n) == EOF) exit(0);
    for (int i = 0;i < n;i++) scanf("%d", &a[i]);
    sort(a, a + n);
}

void work(){
    int ans = n + 1;
    int cur = 0;
    for (int i = 0;i < n;i++){
        if (m > a[i]){
            m += a[i];
            if (i >= n - 1) ans = min(ans, cur);
        }
        else{
            ans = min(ans, cur + (n - i));
            if (m <= 1) break;
            m += m - 1;
            cur += 1;
            i -= 1;
        }
    }
    printf("%d\n", ans);
}

int main(){
#ifdef LATTE
//    freopen("a.in", "r", stdin);
//    freopen("A-small-attempt0.in", "r", stdin);
//    freopen("A-small-attempt0.out", "w", stdout);
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
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
