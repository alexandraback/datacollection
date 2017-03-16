#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

#define REP(AA,BB) for(int AA=0; AA<(BB); ++AA)
#define FOR(AA,BB,CC) for(int AA=(BB); AA<(CC); ++AA)
#define FC(AA,BB) for(__typeof((AA).begin()) BB=(AA).begin(); BB!=(AA).end(); ++BB)
#define SZ(AA) ((int)((AA).size()))
#define ALL(AA) (AA).begin(), (AA).end()
#define PB push_back
#define MP make_pair

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;
typedef long double LD;

bool pal(LL n) {
    VI s;
    while (n > 0) {
        s.PB(n % 10);
        n /= 10;
    }
    VI sr = s; reverse(ALL(s));
    return s == sr;
}

bool square(LL n) {
    int s = (int)sqrt(n);
    for (int i = -1; i <= 1; ++i) {
        int d = max(0, s + i);
        if ((LL)d * d == n && pal(d)) {
            return true;
        }
    }
    return false;
}

int main(void) {
    vector<LL> P;
    for (int i = 1; i < 10000000; ++i) {
        LL even = i, odd = i;
        for (int k = 0, j = i; j > 0; j /= 10, ++k) {
            even = even * 10 + j % 10;
            if (k > 0) {
                odd = odd * 10 + j % 10;
            }
        }
        if (square(even)) {
            P.PB(even);
        }
        if (square(odd)) {
            P.PB(odd);
        }
    }
    sort(ALL(P));
    P.PB(100000000000000000LL);
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        LL a, b; scanf("%lld%lld", &a, &b);
        int res = upper_bound(ALL(P), b) - lower_bound(ALL(P), a);
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}


