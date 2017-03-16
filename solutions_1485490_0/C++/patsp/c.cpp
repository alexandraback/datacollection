#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <complex>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,start,end) for (int var=(start); var<=(end); ++var)
#define FORD(var,start,end) for (int var=(start); var>=(end); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector< vector<int> > VVI;
typedef vector< vector<bool> > VVB;

static LL a[110];
static LL b[110];
static int A[110];
static int B[110];
static int N, M;

static LL go(int i, int j) {
    if (i >= N || j >= M) return 0LL;

    if (A[i] == B[j]) {
        LL ans = go(i+1, j+1);
        if (a[i] > b[j]) {
            a[i] -= b[j];
            ans = max(ans, b[j] + go(i, j+1));
            a[i] += b[j];
        } else {
            b[j] -= a[i];
            ans = max(ans, a[i] + go(i+1, j));
            b[j] += a[i];
        }
        return ans;
    } else {
        return max(go(i+1, j+1), max(go(i, j+1), go(i+1, j)));
    }
}

int main() {
    int nTests = 0;
    scanf("%d\n", &nTests);

    FOR (test, 1, nTests) {
        scanf("%d%d", &N, &M);
        REP (i, N) {
            scanf("%lld %d", &a[i], &A[i]);
        }

        REP (i, M) {
            scanf("%lld %d", &b[i], &B[i]);
        }

        printf("Case #%d: %lld", test, go(0, 0));

        printf("\n");
    }

    return 0;
}
