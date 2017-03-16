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


char buff[150];

void solve() {
    char c = '+';
    scanf("%s", &buff);
    int len = strlen(buff);
    int ans = 0;
    for (int i = len - 1; i >= 0; --i) {
        if (buff[i] != c) {
            ++ans;
            c = buff[i];
        }
    }
    printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
    }

    return 0;
}
