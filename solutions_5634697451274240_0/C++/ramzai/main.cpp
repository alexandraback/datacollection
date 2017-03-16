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

int doit(const string& s) {
    VI a(SIZE(s));

    REP(i, SIZE(s)) {
        a[i] = (s[i] == '+') ? 1 : -1;
    }

    int state = a[0];
    int moves = 0;
    FOR(i, 1, SIZE(s) - 1) {
        if (s[i] != s[i - 1]) {
            ++moves;
            state = -state;
        }
    }
    if (state == -1) ++moves;
    return moves;
}

int main() {
    int T;
    scanf("%d", &T);
    REP(zzz, T) {
        string s;
        cin >> s;
        printf("Case #%d: %d\n", zzz + 1, doit(s));
    }

    return 0;
}
