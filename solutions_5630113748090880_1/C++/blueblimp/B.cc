#include <algorithm>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define CLR(x,a) memset(x,a,sizeof(x))
#define setmin(a,b) a = min(a,b)
#define PB push_back
#define FORALL(i,v) for(typeof((v).end())i=(v).begin();i!=(v).end();++i)
#define MP make_pair
#define A first
#define B second
#define RF(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define BEND(v) (v).begin(),(v).end()
#define SZ(v) int((v).size())
#define FORI(i,v) FOR(i,SZ(v))
typedef long double ld;
typedef long long ll;

int N;
int M;
int loc[128];
int ans[64];
void doit(int cas)
{
    int rows[128][64];

    scanf(" %d", &N);
    assert(2 <= N && N <= 50);
    M = 2*N - 1;

    FOR(i,M) {
        FOR(j,N) {
            scanf(" %d", &rows[i][j]);
        }
    }

    memset(loc, -1, sizeof(loc));

    vector<int> idxs;
    FOR(i,M) idxs.push_back(i);

    int lo = 0;
    int hi = N-1;

    while (true) {
        if (lo == hi) break;

        assert(lo < N);
        sort(BEND(idxs),
            [lo, &rows](int i, int j) {
                return rows[i][lo] < rows[j][lo];
            });

        int mn1 = -1, mn2 = -1;
        FOR(i,M) if (loc[idxs[i]] == -1) {
            if (mn1 == -1) {
                mn1 = idxs[i];
            } else {
                mn2 = idxs[i];
                break;
            }
        }
        assert(mn2 != -1);

        if (rows[mn1][lo] != rows[mn2][lo]) break;
        //printf("  at position %d, rows %d and %d\n", lo, mn1, mn2);

        loc[mn1] = loc[mn2] = lo;

        ++lo;
    }

    while (true) {
        if (lo == hi) break;

        assert(hi >= 0);
        sort(BEND(idxs),
            [hi, &rows](int i, int j) {
                return rows[i][hi] > rows[j][hi];
            });

        int mx1 = -1, mx2 = -1;
        FOR(i,M) if (loc[idxs[i]] == -1) {
            if (mx1 == -1) {
                mx1 = idxs[i];
            } else {
                mx2 = idxs[i];
                break;
            }
        }
        assert(mx2 != -1);

        if (rows[mx1][hi] != rows[mx2][hi]) break;
        //printf("  at position %d, rows %d and %d\n", hi, mx1, mx2);

        loc[mx1] = loc[mx2] = hi;

        --hi;
    }

    assert(lo == hi);

    int unused = 0;
    while (loc[unused] != -1 && unused < M) ++unused;
    assert(unused < M);

    memset(ans, -1, sizeof(ans));
    FOR(i, M) {
        int where = loc[i];
        if (where == -1) {
            assert(i == unused);
            ans[lo] = rows[i][lo];
        } else {
            int what = rows[i][lo];
            if (ans[where] == -1 || what != rows[unused][where]) {
                ans[where] = what;
            }
        }
    }

    printf("Case #%d:", cas);
    FOR(i, N) {
        printf(" %d", ans[i]);
    }
    printf("\n");
}

int T;
int main() {
    scanf(" %d", &T);
    assert(1 <= T && T <= 100);
    FOR(cas,T) doit(cas+1);
    return 0;
}
