//T-shirt is honor for programmers!
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <sstream>
#define inf 1000000007
#define eps 1e-8
#define M 1005
#define For(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
long long r;

double calc(int x) {
    return 2.0 * r * x + x + 2.0 * (x - 1) * x;
}

int main(int argc, char** argv) {
    freopen("123.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    int cs = 0;
    while (T--) {
        cs++;
        long long t;
        scanf("%lld%lld", &r, &t);
        long long low = 1, high = inf, mid;
        long long ans;
        while (low <= high) {
            mid = (high + low) / 2;
            if (calc(mid) <= t) {
                ans = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        printf("Case #%d: %lld\n", cs, ans);
    }

    return 0;
}

