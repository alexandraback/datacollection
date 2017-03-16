#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <string>
#include <memory>
#include <cstring>
#include <climits>
#include <cassert>
#include <algorithm>
#include <cstdio>
#include <set>
#include <cstdlib>

using namespace std;

#define REP(i, n) for (int (i) = 0; (i) < (n); ++i)
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); ++i)
#define FORD(i, a, b) for (int (i) = (a); (i) >= (b); --i)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) (int)((a).size())

#define DBG(x) cout << #x << " = " << (x) << '\n'

typedef vector<int> VI;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

int doit(int K, int C, int S) {
    LL res = 1;
    REP(i, C - 1) res *= K;
    REP(i, K) printf(" %lld", res * i + 1);
}

int main() {
    int T;
    scanf("%d", &T);
    REP(zzz, T) {
        int K, C, S;
        scanf("%d %d %d", &K, &C, &S);
        printf("Case #%d:", zzz + 1);
        doit(K, C, S);
        printf("\n");
    }

    return 0;
}
