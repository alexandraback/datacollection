#include <iostream>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <map>
#include <algorithm>
#include <set>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
#define prev qwerty
const int MAXN = 1000000;
int dp[1000005];
long long n;
long long rev(long long n) {
    long long ret = 0;
    while (n > 0) {
        ret = ret * 10 + n % 10;
        n /= 10;
    }
    return ret;
}
void solve() {
    cin >> n;
    cout << dp[n] << endl;
}
int main(){
    freopen("input.txt","r",stdin);
   //    freopen("/home/furko/Downloads/A-small-attempt0.in", "r", stdin);
    //freopen("/home/furko/Downloads/A-small-attempt0.out", "w", stdout);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    dp[0] = 0;
    for (int i = 1; i <= MAXN; ++i) {
        dp[i] = dp[i - 1] + 1;
        int m = rev(i);
        if (m < i && i % 10 != 0) {
            dp[i] = min(dp[i], dp[m] + 1);
        }
    }
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
