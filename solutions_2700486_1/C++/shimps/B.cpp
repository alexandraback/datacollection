#include <cstring>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>

using namespace std;

double dp[2048][2048];

double do_case() {
    int N;
    cin >> N;
    int mi = 1, ma = 1000;
    while(mi < ma) {
        int mid = (mi + ma + 1) / 2;
        if(2*mid*(mid+1) - 3*mid <= N) mi = mid;
        else ma = mid - 1;
    }
    int k = mi;
    int x, y;
    cin >> x >> y;
    if(abs(x)+y <= 2*(k-1)) return 1;
    if(abs(x)+y > 2*k) return 0;
    int r = N - 2*k*(k+1) + 3*k;
    if(x == 0) return 0;
    x = abs(x);
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    double res = 0;
    for(int i=1;i<=2*k && i<=r;i++) {
        dp[0][i] = dp[0][i-1]/2;
        dp[i][0] = dp[i-1][0]/2;
        if(i == r && y <= i-1) res += dp[i][0];
    }
    for(int i=1;i<=2*k && i<=r;i++) for(int j=1;j<=2*k && i+j<=r;j++) {
        dp[i][j] = (dp[i-1][j] + dp[i][j-1])/2;
        if(j == 2*k) dp[i][j] += dp[i-1][j]/2;
        if(i == 2*k) dp[i][j] += dp[i][j-1]/2;
        if(i+j == r && y <= i-1) res += dp[i][j];
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    for(int it=1;it<=T;it++) cout << "Case #" << it << ": " << fixed << setprecision(9) << do_case() << endl;
    return 0;
}
