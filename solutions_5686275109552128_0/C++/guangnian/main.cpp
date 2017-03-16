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
#include <assert.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<int,int> PII;
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define inf (1<<30)
const int N = 105;
int p[1005];
int dp[1005][1005];
int main()
{
    freopen("/Users/junchen/topcoder/tc/tc/A-small-attempt0.in", "r", stdin);
    freopen("/Users/junchen/topcoder/tc/tc/x1.out", "w", stdout);
    int T;
    cin >> T;
    //cout << T << endl;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 1000; i++) {
        for (int j = i+1; j <= 1000; j++) {
            dp[j][i] = dp[j/2][i] + dp[(j+1)/2][i] + 1;
            for (int k=1; k*2 <= j; k++) {
                dp[j][i] = min(dp[j][i], dp[k][i] + dp[j-k][i] + 1);
            }
        }
    }
    for (int ca = 1; ca <= T; ca++) {
        int d, ma = 1<<30;
        cin >> d;
        //cout << "d=" << d << endl;
        for (int i = 0; i < d; i++) {
            cin >> p[i];
            //cout << p[i] << " ";
        }
        //cout << endl;
        for (int i = 1; i <= 10; i++) {
            int tp = i;
            for (int j = 0; j < d; j++) {
                tp += dp[p[j]][i];
            }
            //cout << "i=" << i << " tp=" << tp << endl;
            ma = min(ma, tp);
        }
        printf("Case #%d: %d\n", ca, ma);
    }
}