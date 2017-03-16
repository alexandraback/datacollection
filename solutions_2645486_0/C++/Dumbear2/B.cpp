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
#include <climits>
using namespace std;
#define PB push_back
#define MP make_pair
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int t, dp[16], buf[16];

void solve() {
    int e, r, n, v;
    scanf("%d%d%d", &e, &r, &n);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v);
        memset(buf, 0, sizeof(buf));
        for (int j = 0; j <= e; ++j) {
            for (int k = 0; k <= j; ++k) {
                int tmp = min(j - k + r, e);
                buf[tmp] = max(buf[tmp], dp[j] + k * v);
            }
        }
        memcpy(dp, buf, sizeof(buf));
    }
    int ans = 0;
    for (int i = 0; i <= e; ++i)
        ans = max(ans, dp[i]);
    printf("Case #%d: %d\n", ++t, ans);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}
