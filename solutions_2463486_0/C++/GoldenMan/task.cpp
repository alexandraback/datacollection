#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

vector <long long> p;

int pal(long long x) {
    int len = 1, a[20];
    long long power = 10;
    while (x >= power) {
        ++len;
        power *= 10;
    }
    for (int i = 0; i < len; ++i) {
        a[i] = x % 10;
        x /= 10;
    }
    for (int i = 0; i < len; ++i) {
        if (a[i] != a[len - i - 1]) return 0;
    }
    return 1;
}

void init() {
    for (int i = 1; i <= 10000000; ++i) {
        if (!pal(i)) continue;
        if (!pal((long long) i * i)) continue;
        p.push_back((long long) i * i);
    }
}

void solve(int _case) {
    long long a, b;
    scanf("%I64d%I64d", &a , &b);
    int cnt  = 0;
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] >= a && p[i] <= b) ++cnt;
    }
    printf("Case #%d: %d\n", _case, cnt);
}

int _;

int main() {
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    init();
    scanf("%d\n", &_);
    for (int __ = 0; __ < _; ++__) {
        solve(__ + 1);
    }
    return 0;
}
