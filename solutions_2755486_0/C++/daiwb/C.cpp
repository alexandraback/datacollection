#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define DIFF 200

typedef long long LL;

class attack {
public:
    LL d, w, e, s;
    bool operator<(const attack& rhs) const {
        return d < rhs.d;
    }
};

LL hh[505];

void run() {
    int N;
    cin >> N;
    vector<attack> mm;
    REP(i,N) {
        LL d, n, w, e, s, dd, dp, ds;
        cin >> d >> n >> w >> e >> s >> dd >> dp >> ds;
        w += DIFF;
        e += DIFF;
        REP(j,n) {
            attack tmp;
            tmp.d = d;
            tmp.w = w;
            tmp.e = e;
            tmp.s = s;
            mm.push_back(tmp);

            d += dd;
            w += dp;
            e += dp;
            s += ds;
        }
    }
    sort(mm.begin(), mm.end());

    int res = 0;
    memset(hh, 0, sizeof(hh));
    REP(i,mm.size()) {
        int idx = i;
        while (idx + 1 < mm.size() && mm[i].d == mm[idx + 1].d) ++idx;

        FOR(j,i,idx) {
            bool flag = false;
            FOR(tt,mm[j].w,mm[j].e-1) {
                if (hh[tt] < mm[j].s) {
                    flag = true;
                    break;
                }
            }
            if (flag) ++res;
        }

        FOR(j,i,idx) {
            FOR(tt,mm[j].w,mm[j].e-1) {
                hh[tt] = max(hh[tt], mm[j].s);
            }
        }

        i = idx;
    }

    cout << res << endl;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
