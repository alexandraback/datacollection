#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>

using namespace std;

const int MAX_N = 10;
const int MAX_n = 10;

struct Attack {
    long long day;
    long long str;
    int w, e;

    Attack(long long d = 0, long long s = 0, int nw = 0, int ne = 0) {
        day = d;
        str = s;
        w = (nw + 500);
        w += 2 * (w - 500);
        e = ne + 500;
        e += 2 * (e - 500);
    }

    bool operator<(const Attack& other) const {
        return day < other.day;
    }
};

int N;
int nxt;
Attack attacks[MAX_N * MAX_n];

long long wall[1000];

int main() {
    int tests; cin >> tests;
    for (int test_id = 1; test_id <= tests; ++test_id) {
        scanf("%d", &N);
        nxt = 0;
        for (int i = 0; i < N; ++i) {
            long long d, n, w, e, s, dd, dp, ds;
            cin >> d >> n >> w >> e >> s >> dd >> dp >> ds;
            for (int j = 0; j < n; ++j) {
                attacks[nxt++] = Attack(d, s, w, e);
                d += dd;
                s += ds;
                w += dp;
                e += dp;
            }
        }
        sort(attacks, attacks + nxt);
        memset(wall, 0, sizeof(wall));
        int res = 0;
        for (int i = 0; i < nxt;) {
            for (int j = i; j < nxt && attacks[j].day == attacks[i].day; ++j) {
                bool succ = false;
                for (int k = attacks[j].w; k <= attacks[j].e; ++k) {
                    if (wall[k] < attacks[j].str)
                        succ = true;
                }
                if (succ) ++res;
            }
            int j;
            for (j = i; j < nxt && attacks[j].day == attacks[i].day; ++j) {
                for (int k = attacks[j].w; k <= attacks[j].e; ++k)
                    wall[k] = max(wall[k], attacks[j].str);
            }
            i = j;
        }
        printf("Case #%d: %d\n", test_id, res);
    }
    return 0;
}
