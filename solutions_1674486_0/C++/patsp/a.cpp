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

// typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector< vector<int> > VVI;
typedef vector< vector<bool> > VVB;

static bool matrix[1010][1010];
static bool visited[1010];
static int N;

static bool dfs(int i) {
    if (visited[i]) return true;

    visited[i] = true;

    bool ans = false;
    REP (j, N) {
        if (matrix[i][j]) {
            ans |= dfs(j);
        }
        if (ans) break;
    }

    return ans;
}

int main() {
    int nTests = 0;
    scanf("%d\n", &nTests);

    FOR (test, 1, nTests) {
        memset(matrix, 0, sizeof(matrix));
        N = 0;
        scanf("%d", &N);

        REP (i, N) {
            int M = 0;
            scanf("%d", &M);
            REP (k, M) {
                int j = 0;
                scanf("%d", &j);
                --j;
                matrix[i][j] = true;
            }
        }
        // REP (i, N) {
        //     REP (j, N) {
        //         cout << matrix[i][j];
        //     }
        //     cout << endl;
        // }

        bool ans = false;
        REP (i, N) {
            memset(visited, 0, sizeof(visited));
            if (dfs(i)) {
                ans = true;
                break;
            }
        }

        printf("Case #%d: ", test);
        if (ans) {
            printf("Yes");
        } else {
            printf("No");
        }
        printf("\n");
    }

    return 0;
}
