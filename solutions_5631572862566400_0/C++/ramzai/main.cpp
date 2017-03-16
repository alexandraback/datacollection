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

int bf[1010];

int doit(int N)
{
    int best = 0;
    vector<int> a(N);
    REP(i, N) a[i] = i;
    REP(i, N) --bf[i];
    do {
        FORD(j, N, best + 1) {
            bool success = true;
            REP(k, j) {
                int f = bf[a[k]];
                if (a[(k + j - 1) % j] != f && a[(k + 1) % j] != f) {
                    success = false;
                    break;
                }
            }
            if (success) {
                best = j;
                break;
            }
        }
    } while(next_permutation(ALL(a)));
    return best;
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
