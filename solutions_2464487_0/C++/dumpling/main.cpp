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
int T;
int64 r, t;

int64 fun(int64 r, int64 k) {
    return (2 * r + 2 * k - 1) * k;
}

int64 solve() {
    scanf("%lld%lld", &r, &t);
    int64 left = 1, right = min(t, 10000000000ll), mid, ret, ans;
    while (left <= right) {
        mid = (right - left) / 2 + left;
        ret = fun(r, mid);
        if (ret <= 0 || ret > t)
            right = mid - 1;
        else if (ret == t) {
            ans = mid;
            break;
        } else {
            ans = mid;
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d: %lld\n", i, solve());
    }

    return 0;
}