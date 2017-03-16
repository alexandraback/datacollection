#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cassert>
#include<cstdio>
#include<cstring>
#include<ctime>

#define DEBUGLEVEL
#ifdef DEBUGLEVEL
#define printf_debug(fmt, args...) fprintf(stderr, fmt, ##args)
#else
#define printf_debug(fmt, args...)
#endif

typedef long long llong;

using namespace std;

int main() {
#ifdef DEBUG
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.out", "w", stdout);
#endif
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        int a, b, k;
        cin >> a >> b >> k;
        int ans = 0;
        for(int i = 0; i < a; ++i) {
            for(int j = 0; j < b; ++j) {
                if((i & j) < k) ans++;
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}