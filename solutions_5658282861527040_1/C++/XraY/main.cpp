#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cassert>
#include <ctime>


using namespace std;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll rdtsc() {
    ll tmp;
    asm("rdtsc" : "=A"(tmp));
    return tmp;
}

inline int myrand() {
    return abs((rand() << 15) ^ rand());
}

inline int rnd(int x) {
    return myrand() % x;
}

#define TASKNAME "text"
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
#define INF ((int)1e9)
#define sqr(x) ((x) * (x))         
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

const int maxl = 31;
const int n = 3;

long long d[maxl][1 << n];

bool solve(int testCase) {
    printf("Case #%d: ", testCase);
    int a[n];
    if (scanf("%d%d%d", &a[0], &a[1], &a[2]) < 3)
        return 0;
    for (int i = 0; i < n; ++i)
        --a[i];

    for (int len = 0; len < maxl; ++len) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            long long &ans = d[len][mask];
            ans = 0;
            
            if (!len) {
                ans = 1;
                continue;
            }

            int vals[n];
            for (int i = 0; i < n; ++i)
                vals[i] = ((mask >> i) & 1) ? 1 : ((a[i] >> (len - 1)) & 1);
            for (int nvalues = 0; nvalues < (1 << (n - 1)); ++nvalues) {
                int cur[n - 1];
                bool fail = false;
                for (int i = 0; i < n - 1; ++i) {
                    cur[i] = ((nvalues >> i) & 1);
                    if (cur[i] > vals[i]) {
                        fail = true;
                        break;
                    }
                }

                if (fail)
                    continue;

                int curAnd = (cur[0] & cur[1]);
                if (curAnd > vals[2])
                    continue;

                int nmask = mask;
                for (int i = 0; i < n - 1; ++i) {
                    if (cur[i] < vals[i])
                        nmask |= (1 << i);
                }

                if (curAnd < vals[2])
                    nmask |= (1 << (n - 1));

                ans += d[len - 1][nmask];
            }
        }
    }

    printf(LLD "\n", d[maxl - 1][0]);
    return 1;
}

int main() {
    srand(rdtsc());
#ifdef DEBUG
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
#endif
    
    int maxt;
    while (scanf("%d", &maxt) == 1) {
        for (int t = 0; t < maxt; ++t)
            assert(solve(t + 1));
        
        #ifdef DEBUG
            eprintf("%.18lf\n", (double)clock() / CLOCKS_PER_SEC);
        #endif
    }
    return 0;
}
