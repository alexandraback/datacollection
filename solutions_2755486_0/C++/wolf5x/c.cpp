#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<(h);++i)
#define FORD(i,h,l) for(int i=(h)-1;i>=(l);--i)
#define FORIT(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(typeof((c).rbegin()) i=(c).rbegin(); i!=(c).rend(); ++i)

const int maxn = 110;
const int mid = 300;
int T,N;
int dd[maxn], nn[maxn], ww[maxn], ee[maxn], td[maxn], tp[maxn], ts[maxn];
int ss[maxn];

struct ATT{
    int d, w, e, s;
    void set(int _d, int _w, int _e, int _s) {
        d = _d, w = _w, e = _e, s = _s;
    }
}att[110];
int sat;

int h[700], up[700];

bool cmp(const ATT &a, const ATT &b) {
    return a.d < b.d;
}

int main() {
    cin >> T;
    FOR(cas, 1, T+1) {
        sat = 0;
        memset(h, 0, sizeof(h));
        memset(up, 0, sizeof(up));
        cin >> N;
        REP(i, N){
            cin >> dd[i] >> nn[i] >> ww[i] >> ee[i] >> ss[i] >> td[i] >> tp[i] >> ts[i];
            REP(j, nn[i]) {
                att[sat++].set(dd[i]+td[i]*j, mid+ww[i]+tp[i]*j, mid+ee[i]+tp[i]*j, ss[i]+ts[i]*j);
            }
        }
        sort(att, att+sat, cmp);
        int ans = 0;
        for(int p = 0; p < sat; ) {
            int q = p+1;
            while(q < sat && att[p].d == att[q].d) q++;
            FOR(i, p, q) {
                int d = att[i].d, w = att[i].w, e = att[i].e, s = att[i].s;
                bool ok = false;
                FOR(j, w, e) if(s > h[j]) {
                    ok = true;
                    up[j] = max(up[j], s);
                }
                if(ok) ans++;
            }
            REP(i, 700) h[i] = max(h[i], up[i]);
            p = q;
        }
        cout << "Case #" << cas << ": " << ans << endl;
    }
    return 0;
}

