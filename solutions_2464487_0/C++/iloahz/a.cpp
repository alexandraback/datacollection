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

const int MAXN = 1005;
const int INF = 1 << 29;
const long long MOD = 55566677ll;
const int dx[] = {-1, 0, 0, 1, 1, 1, -1, -1};
const int dy[] = {0, -1, 1, 0, 1, -1, -1, 1};

long long r, t;

void prep(){
}

void init(){
    if (scanf("%lld%lld", &r, &t) == EOF) exit(0);
}

inline bool check(long long x){
    long long p = r * 2 + (x + 1) * 2 - 3;
    long long q = t / x;
    if (p <= q){
        return true;
    }
    return false;
}

long long bs(){
    long long p = 1;
    long long q = min(707106780ll, t);
    while (p < q){
        long long m = p + (q - p) / 2;
//        printf("%lld %lld %lld\n", m, calc(m), t);
        if (check(m)){
            p = m + 1;
        }
        else{
            q = m - 1;
        }
    }
    for (long long i = p + 10;i >= p - 10;i--){
//        printf("%lld %lld\n", i, calc(i));
        if (check(i)){
//            exit(0);
            return i;
        }
    }
}

void work(){
    long long ans = bs();
    printf("%lld\n", ans);
}

int main(){
#ifdef LATTE
//    freopen("a.in", "r", stdin);
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
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
