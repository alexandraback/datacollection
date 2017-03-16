#include <iostream>
#include <cassert>
#include "utility/type/ll.hpp"
#include "utility/range.hpp"
using namespace std;
ll reverse(ll x) {
    ll y = 0;
    while (x) {
        y *= 10;
        y += x % 10;
        x /= 10;
    }
    return y;
}
int main() {
    ios_base::sync_with_stdio(false);
    constexpr ll l = 1000001;
    ll dp[l] = {};
    dp[0] = 0;
    for (int i : range(1,l)) {
        dp[i] = dp[i-1]+1;
        if (reverse(i) < i and reverse(reverse(i)) == i) dp[i] = min(dp[i], dp[reverse(i)]+1);
    }
    for (int testcase : range(cin)) {
        ll n; cin >> n;
        assert (n < l);
        cout << "Case #" << testcase+1 << ": " << dp[n] << endl;
    }
    return 0;
}
