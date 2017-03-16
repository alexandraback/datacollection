/*
 * @author: zhenpeng.fang
 * @nickname: dumpling
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <time.h>
#include <stdlib.h>
#include <stack>
#include <queue>
using namespace std;

#define mp make_pair

//%llu
typedef unsigned long long uint64;
typedef long long int64;
typedef pair<int, int> pair2;

const double eps = 1e-8;
int T, n;
char line[128];

bool vowels(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int consecutive(int l, int r) {
    int ret = 0, cnt = 0;
    for (int i = l; i <= r; ++i) {
        if (vowels(line[i]))
            cnt = 0;
        else
            ++cnt;
        if (cnt > ret)
            ret = cnt;
    }
    return ret;
}

int64 solve(int n) {
    int64 ret = 0;
    for (int i = 0; i < strlen(line); ++i)
        for (int j = i; j < strlen(line); ++j)
            if (consecutive(i, j) >= n)
                ++ret;
    return ret;
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%s%d", line, &n);
        printf("Case #%d: %lld\n", t, solve(n));
    }
    return 0;
}