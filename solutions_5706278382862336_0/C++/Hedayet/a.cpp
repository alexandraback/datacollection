#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#define inf 2000000000
#define ll long long
#define Max

using namespace std;

ll gcd(ll a, ll b ) {
    return !b ? a : gcd(b , a % b);
}

int pow2(ll N) {
    return (N&(N - 1)) == 0;
}

int main()
{
    freopen("A2.in", "r", stdin);
    freopen("A2.out", "w", stdout);
    int T;
    cin >> T;
    for(int cas = 1; cas <= T; cas ++) {
        long long a, b;
        scanf("%lld/%lld", &a, &b);
        long long g = gcd(a, b);
        a /= g;
        b /= g;
        int ret = 0;
        while( a < b) {
            ret ++;
            a *= 2;
        }

        if( !pow2(b)) {
            ret = -1;
        }
        printf("Case #%d: ", cas);
        if(ret > -1) {
            printf("%d\n", ret);
        } else {
            puts("impossible");
        }
    }
    return 0;
}
