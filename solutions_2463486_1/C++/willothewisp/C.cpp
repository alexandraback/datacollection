#include <cstdio>

#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)

//const ll LIM = int(1e7);

//int tmp[20];
//bool ispal(ll n) {
//    int e = 0;
//    while (n) { tmp[e++] = n % 10; n /= 10; }
//    REP(i, e) if (tmp[i] != tmp[e - 1 - i]) return false;
//    return true;
//}

//ll sp[LIM];
//int nsp = 0;
//void precomp(ll lim) {
//    for (ll x = 1; x <= lim; ++x) {
//        if (!ispal(x) || !ispal(x*x)) continue;
//        sp[nsp++] = x*x;
//    }
//}

const ll sp[39] = {1ll, 4ll, 9ll, 121ll, 484ll, 10201ll, 12321ll, 14641ll, 40804ll, 44944ll, 1002001ll, 1234321ll, 4008004ll, 100020001ll, 102030201ll, 104060401ll,
    121242121ll, 123454321ll, 125686521ll, 400080004ll, 404090404ll, 10000200001ll, 10221412201ll, 12102420121ll, 12345654321ll, 40000800004ll, 1000002000001ll,
    1002003002001ll, 1004006004001ll, 1020304030201ll, 1022325232201ll, 1024348434201ll, 1210024200121ll, 1212225222121ll, 1214428244121ll, 1232346432321ll,
    1234567654321ll, 4000008000004ll, 4004009004004ll};
const int nsp = 39;

int main() {
    //precomp(LIM);

    int T;
    scanf("%d", &T);

    REP(t, T) {
        ll A, B;
        scanf("%lld %lld", &A, &B); ++B;
        printf("Case #%d: %d\n", t + 1, int(lower_bound(sp, sp + nsp, B) - lower_bound(sp, sp + nsp, A)));
    }
}
