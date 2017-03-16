#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <set>
#include <bitset>
#include <map>

#define UREP(i,n) for(unsigned int i=0;i<n;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define FRVR for(;;)

typedef unsigned long long int ULINT;
typedef long long int LINT;

const double EPS = 1e-6;

using namespace std;

const int MAX = 1000007;

int revnum(int i) {
    int ret = 0;
    while(i) {
        ret = ret * 10 + i % 10;
        i/=10;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);

    int * dp = new int[MAX*10];
    int * reverse = new int[MAX*10];

    UREP(i, MAX) {
        reverse[i] = revnum(i);
        dp[i] = MAX*10;
    }

    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i < MAX; ++i) {
        dp[i] = min(dp[i-1]+1, dp[i]);
        dp[reverse[i]] = min(dp[i]+1, dp[reverse[i]]);

         // cout << i << ' ' << dp[i] << endl;
    }

    int t;
    cin >> t;
    REP(i, t) {
        int n;
        cin >> n;
        cout <<"Case #" << i+1 << ": " << dp[n] << endl;
    }


    return 0;
}
