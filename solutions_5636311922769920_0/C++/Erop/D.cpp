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



void solve() {
    int K, C, S;
    scanf("%d%d%d", &K, &C, &S);
    for (int i = 0; i < S; ++i) {
        printf("%d ", i + 1);
    }
    puts("");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
    }

    return 0;
}
