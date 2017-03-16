#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

map<long long, long long> dp;

long long reverse(long long n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return stoll(s);
}

long long solve(long long n) {
    long long& ret = dp[n];
    if (ret) return ret;
    ret = n;
    int dig = n % 10;
    long long v = dig;
    long long w = n / 10;
    bool found = false;
    for (long long p = 10; ; p *= 10) {
        if (v > 0) {
            long long t = n - (v - 1);
            long long z = reverse(t);
            if (z < n) {
                found = true;
                ret = min(ret, solve(z) + (v - 1) + (t != z));
            }
        }
        v += p * (w % 10);
        w /= 10;
        if (v == n) break;
    }
    if (!found || dig == 0) {
        ret = min(ret, solve(n - 1) + 1);
    }
    return ret;
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int tt;
    cin >> tt;
    dp[1] = 1;
    for (int ti = 1; ti <= tt; ++ti) {
        long long n;
        cin >> n;
        long long answer = solve(n);
        cout << "Case #" << ti << ": " << answer << '\n';
    }
}
