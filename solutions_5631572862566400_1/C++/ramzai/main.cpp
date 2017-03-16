#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <list>
#include <memory>
#include <string>
#include <vector>
#include <functional>
#include <climits>
#include <cstring>
#include <cstdio>
using namespace std;

#define PB push_back
#define MP make_pair
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define SIZE(v) (int)(v).size()
#define ALL(v) (v).begin(), (v).end()
typedef long long LL;
#define DBG(x) cout << #x << " = " << x << endl
#define DBGV(v) REP(i, SZ((v))) cout << #v << '[' << i << "] = " << (v)[i] << endl

#define MAXN 1000

int bf[MAXN];
int seen[MAXN];
int is_pair[MAXN];
int chain[MAXN];

int max_cycle(int N) {
    int res = 0;
    REP(i, N) {
        memset(seen, 0, sizeof(seen));
        int l = 1;
        int x = i;
        seen[x] = 1;
        while (true)
        {
            x = bf[x];
            ++l;

            if (x == i) {
                res = max(res, l - 1);
                break;
            }
            if (seen[x]) break;

            seen[x] = 1;
        }
    }
    return res;
}

int doit(int N)
{
    memset(seen, 0, sizeof(seen));
    memset(is_pair, 0, sizeof(is_pair));
    REP(i, N) {
        --bf[i];
    }

    int pair_cnt = 0;
    REP(i, N) {
        if (i == bf[bf[i]]) {
            is_pair[i] = 1;
            pair_cnt++;
        }
    }
    pair_cnt /= 2;

    int best = max_cycle(N);
    if (pair_cnt == 0) return best;

    memset(chain, 0, sizeof(chain));
    REP(i, N) if (!is_pair[i]) {
        memset(seen, 0, sizeof(seen));
        int x = i;
        int l = 0;
        seen[x] = 1;
        while (true)
        {
            x = bf[x];
            ++l;
            if (is_pair[x]) {
                chain[x] = max(chain[x], l);
                break;
            }
            if (seen[x]) break;
            seen[x] = 1;
        }
    }

    int pair_res = 0;
    REP(i, N) if (is_pair[i]) {
        pair_res += (chain[i] + 1);
    }
    return max(pair_res, best);
}

int main()
{
    int testCount;
    cin >> testCount;
    FOR(zzz, 1, testCount) {
        int N;
        cin >> N;
        REP(i, N) cin >> bf[i];
        cout << "Case #" << zzz << ": " << doit(N) << '\n';
    }

    return 0;
}
