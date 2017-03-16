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

int pr[2000005];

string inttostr(long long n) {
    string ret = "";
    while (n > 0) {
        ret = (char)(n % 10 + '0') + ret;
        n /= 10;
    }
    return ret;
}

long long strtoint(string str) {
    long long ret = 0;
    for (int i = 0; i < str.size(); ++i) {
        ret = ret * 10 + str[i] - '0';
    }
    return ret;
}

long long run(long long n) {
    if (n < 10) return dp[n];
    string str = inttostr(n);
    int len = str.size() + 1;
    len /= 2;
    long long cur = 0;
    for (int i = len; i < str.size(); ++i) {
        cur = cur * 10 + str[i] - '0';
        str[i] = '0';
    }
    if (cur == 0) {
        return 1 + run(n - 1);
    }

    long long ans = cur - 1;
    str[str.size() - 1] = '1';
    long long val = strtoint(str);
    long long sw = rev(val);
    if (sw == val) {
        return ans + 1 + run(val - 1);
    }

    return ans + 1 + run(sw);
}

void solve() {
    cin >> n;
    cout << run(n) << endl;
}
int main(){
    freopen("input.txt","r",stdin);
   //    freopen("/home/furko/Downloads/A-small-attempt0.in", "r", stdin);
    //freopen("/home/furko/Downloads/A-small-attempt0.out", "w", stdout);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    dp[0] = 0;
    int ans = 0;
    for (int i = 1; i <= MAXN; ++i) {
        dp[i] = dp[i - 1] + 1;
        pr[i] = i - 1;
        int m = rev(i);
        if (m < i && i % 10 != 0) {
            dp[i] = min(dp[i], dp[m] + 1);
            if (dp[i] == dp[m] + 1) {
                pr[i] = m;
            }
        }
        ans = max(ans, dp[i]);
    }
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
