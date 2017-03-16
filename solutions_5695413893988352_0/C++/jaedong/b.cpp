#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
const long long INF = 2000000000000000000LL;
char s[2][MAX], sts[2][MAX];
int len;
typedef tuple<long long, long long, long long> sol_t;
sol_t best;

void solve(int step) {
    if (step == 0) {
        long long sola = atoll(sts[0]);
        long long solb = atoll(sts[1]);
        sol_t cand(llabs(sola - solb), sola, solb);
        //printf("%s %s\n", sts[0], sts[1]);
        if (best > cand)
            best = cand;
    } else {
        int which = step > len ? 1 : 0;
        int d = step - len * which - 1;
        assert(0 <= d && d < len);
        if (s[which][d] == '?') {
            for (char c = '0'; c <= '9'; c++) {
                sts[which][d] = c;
                solve(step-1);
            }
        } else {
            sts[which][d] = s[which][d];
            solve(step-1);
        }
    }
}

int main() {
    int cases;
    scanf("%d", &cases);
    for (int cs = 1; cs <= cases; cs++) {
        scanf("%s%s", s[0], s[1]);

        len = int(strlen(s[0]));
        best = sol_t(INF, INF, 0);
        memset(sts, 0, sizeof(sts));

        solve(2 * len);
        printf("Case #%d: %0*lld %0*lld\n", cs, len, get<1>(best), len, get<2>(best));
    }
}
