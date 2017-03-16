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

const int MAXN = 55;
const int INF = 1 << 29;
const long long MOD = 55566677ll;

int n, x, y;
//double p[MAXN][MAXN];

void prep(){
//    memset(p, 0, sizeof(p));
//    for (int i = 0;i < 20;i++){
//
//    }
}

void init(){
    if (scanf("%d%d%d", &n, &x, &y) == EOF) exit(0);
    x = abs(x);
}

inline int f(int x){
    return x * (x + 1) * 2 - x * 3;
}

double q[MAXN];
void work(){
    double ans = 0;
    int m = (x + y) / 2 + 1;
    if (f(m) <= n){
        ans = 1.0;
    }
    else if (f(m - 1) >= n){
        ans = 0;
    }
    else{
        n -= f(m - 1);
        if (n >= 2 * m - 2 + y + 1){
            ans = 1;
        }
        else{
//            printf("n = %d\n", n);
            q[0] = pow(0.5, n);
            for (int i = 1;i <= n;i++){
                q[i] = q[i - 1] * (n - i + 1) / i;
            }
            double s = 0;
            for (int i = max(0, n - (2 * m - 2));i <= n && i <= 2 * m - 2;i++){
//                printf("i = %d %.6f\n", i, q[i]);
                s += q[i];
            }
            ans = 0;
            for (int i = n - (2 * m - 2);i <= n && i <= 2 * m - 2;i++){
                if (i > y) ans += q[i] / s;
            }
        }
    }
    printf("%.8f\n", ans);
}

int main(){
#ifdef LATTE
    freopen("b.in", "r", stdin);
//    freopen("B-small-attempt0.in", "r", stdin);
//    freopen("B-small-attempt0.out", "w", stdout);
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
