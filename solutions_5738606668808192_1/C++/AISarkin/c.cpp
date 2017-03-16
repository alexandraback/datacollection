#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>

using namespace std;

#define TASKNAME ""

void solve(int test_number);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(9);
    cerr.setf(ios::fixed);
    cerr.precision(3);
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve(i);
    }
}

string binary(long long x) {
    string ans;
    while (x) {
        ans += (x & 1) + '0';
        x >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve(int test_number) {
    cout << "Case #" << test_number + 1 << ":\n";
    int n, j;
    cin >> n >> j;
    int k = n / 2;
    for (int mask = 0; mask < (1 << (k - 2)) && j > 0; mask++) {
        long long sum = (1ll << (k - 1)) + 1 + (mask << 1);
        long long ans = sum + (sum << (k + (n & 1)));
        cout << binary(ans) << " ";
        for (int q = 2; q <= 10; q++) {
            long long div = 0;
            long long p = 1;
            for (int l = 0; l < k; l++) {
                if (sum & (1 << l)) {
                    div += p;
                }
                p *= q;
            }
            cout << div << " ";
        }
        cout << endl;
        j--;
    }
}
