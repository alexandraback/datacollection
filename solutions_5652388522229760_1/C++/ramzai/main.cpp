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

int MD = 1e9 + 7;

int doit(int n) {
    if (n == 0) return -1;
    int seen[10];
    REP(i, 10) seen[i] = 0;
    for (int x = n; x < 1000000000; x += n) {
        int t = x;
        while (t > 0) {
            seen[t % 10] = 1;
            t /= 10;
        }
        int s = 0; REP(i, 10) s += seen[i];
        if (s == 10) return x;
    }
    return -1;
}

int main() {
    int T;
    scanf("%d", &T);
    REP(zzz, T) {
        int N;
        scanf("%d", &N);

        int res = doit(N);
        if (res == -1) printf("Case #%d: INSOMNIA\n", zzz + 1);
        else printf("Case #%d: %d\n", zzz + 1, res);
    }

    return 0;
}
