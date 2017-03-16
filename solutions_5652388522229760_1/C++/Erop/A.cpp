#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
#pragma comment(linker, "/STACK:167772160")

typedef long long ll;

int add(bool *has, ll n) {
    int ans = 0;
    while(n) {
        int c = n % 10;
        n /= 10;
        if (!has[c]) {
            ++ans;
            has[c] = true;
        }
    }
    return ans;
}

void solve(ll n) {
    if (n == 0) {
        puts("INSOMNIA");
        return;
    }
    bool has[10];
    memset(has, false, sizeof(has));
    int cnt = 0;
    for (ll i = 1; ; ++i) {
        cnt += add(has, i*n);
        if (cnt == 10) {
            printf("%lld\n", i*n);
            return;
        }
    }

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        printf("Case #%d: ", i + 1);
        int n;
        scanf("%d", &n);
        solve(n);
    }

    return 0;
}
