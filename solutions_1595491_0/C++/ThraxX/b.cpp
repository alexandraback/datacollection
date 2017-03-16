#include <vector>

#include <string>
#include <cstdio>

#include <algorithm>
#include <utility>
#include <cstring>

#include <map>
#include <set>

#include <cassert>

#include <numeric>
#include <bitset>

#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>

#include <cmath>
#include <complex>
#include <cstdlib>

#include <list>
#include <deque>
#include <queue>
#include <stack>

#include <functional>
#include <cctype>
#include <ctime>

using namespace std;
typedef long long ll;

#define fill(f, a) memset(f, a, sizeof(f))
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define for_each(s,container) for (typeof((container).begin()) s = (container).begin(); s != (container).end(); s++)

int dp[120][120];
const int INF = 10000000;
int tot[120];


int N(int t, int p) {
    for (int mx = p; mx < 11; ++mx) {
        for (int dd = -2; dd < 1; ++dd)
            if (3 * mx + dd == t && (dd == 0 || mx > 0))
                return 1;
    }
    return 0;
}

int S(int t, int p) {
    for (int mx = max(p, 2); mx < 11; ++mx) {
        for (int dd = -4; dd < -1; ++dd)
            if (3 * mx + dd == t)
                return 1;
    }
    return 0;
}

int main() {
	int t, tCtr;
	scanf("%d", &t);
	for (tCtr = 0; tCtr < t; ++tCtr) {
        int n, s, p;
        fill(dp, 0);
        fill(tot, 0);

        scanf("%d %d %d", &n, &s, &p);
        
        for (int i = 0; i < n; ++i) {
            scanf("%d", &tot[i]);
        }

        for (int i = 1; i < s + 1; ++i)
            dp[0][i] = -INF;

        for (int i = 0; i < n; ++i) {
            dp[i + 1][0] = dp[i][0] + N(tot[i], p);
            for (int j = 0; j < s; ++j)
                dp[i + 1][j + 1] = max(dp[i][j + 1] + N(tot[i], p), dp[i][j] + S(tot[i], p));
        }

		printf("Case #%d: ", tCtr + 1);
        printf("%d\n", dp[n][s]);
	}
	return 0;

}

