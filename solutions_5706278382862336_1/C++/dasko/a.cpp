#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <cassert>

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

const LL A = 1LL << 40;

void test(int t) {
    LL P, Q;
    scanf("%lld/%lld", &P, &Q);
    assert(Q != 0);
    LL d = __gcd(P, Q);
    P /= d;
    Q /= d;
    if (A % Q != 0) {
        printf("Case #%d: impossible\n", t);
        return;
    }
    LL K = (A / Q) * P;
    int b = 0;
    for (b = 0; (1LL << b) <= K; ++b);
    --b;
    printf("Case #%d: %d\n", t, 40 - b);
}

int main(void) {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        test(t);
    }
    return 0;
}
