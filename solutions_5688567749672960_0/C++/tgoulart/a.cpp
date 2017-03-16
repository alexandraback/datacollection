#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

long long reverse(long long x) {
    long long ans = 0;
    while (x) {
        ans = ans * 10ll + (x % 10ll);
        x /= 10ll;
    }
    return ans;
}

long long dp(long long target) {
    vector <long long> table(target + 1, target + 1);
    table[1] = 1;
    for (int i=1; i < target; ++i) {
        long long rev = reverse(i);
        table[i + 1] = min(table[i + 1], table[i] + 1);
        if (rev <= target) {
            table[rev] = min(table[rev], table[i] + 1);
        }
    }
    return table[target];
}

long long minNumbers(long long target) {
    long long current = 1;
    long long ans = 1;

    while (current != target) {
        ++ans;
        long long rev = reverse(current);
        long long nextRev = reverse(current + 1);
//        printf("%lld %lld %lld: %lld %lld\n", target, current, ans, rev, nextRev);
        if ((rev <= target && (nextRev > target || nextRev < rev)) && rev > current) {
            current = rev;
        } else {
            ++current;
        }
    }

    if (ans != dp(target)) {
        printf("fudeu: %lld is %lld not %lld\n", target, dp(target), ans);
        exit(0);
    }

    return ans;
}

void solve(int testNo) {
    cout << "Case #" << testNo << ": ";
    long long target;
    cin >> target;
    cout << dp(target) << endl;
}

int main() {
//    minNumbers(99);
//    return 0;
//    for (int i=1; i <= 10000; ++i) {
//        cout << i << ") " << minNumbers(i) << endl;
//    }
//    return 0;
    int T;
    cin >> T;
    for (int i=1; i <= T; ++i) {
        solve(i);
    }
    return 0;
}
