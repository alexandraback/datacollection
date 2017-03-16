#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define long int64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

int main() {
    int tests, tc = 0;
    for (cin >> tests; tc++ < tests; ) {
        int n;
        string s;
        cin >> n >> s;
        int res = 0, total = 0;
        for (int i = 0; i <= n; ++i) {
            for (; s[i] > '0'; --s[i]) {
                for (; total < i; ++total)
                    ++res;
                ++total;
            }
        }
        printf("Case #%d: %d\n", tc, res);
    }
    return 0;
}
