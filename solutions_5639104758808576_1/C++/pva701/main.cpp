#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef double db;
int solve(int n, const string& str) {
    int s = 0;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (i > s) {
            ans += i - s;
            s = i;
        }
        s += str[i] - '0';
    }
    return ans;
}

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t;
    cin >> t;
    for (int it = 1; it <= t; ++it) {
        int n;
        string s;
        cin >> n >> s;
        printf("Case #%d: %d\n", it, solve(n, s));
    }
    return 0;
}
