#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
//#include <memory>
//#include <thread>
using namespace std;


#define INF 1e+9
#define mp make_pair
#define lint long long
#define pii pair<int, int>
#define BITS 32

/*
long long getBound(int m, int b) {
    if (m == 0) return b;
    int ii = 0;
    while (((1LL << ii) & m) == 0) {
        ii++;
    }
    //cerr << ii << endl;
    if ((b >> ii) > (m >> ii)) return 1LL << ii;
    if ((b >> ii) == (m >> ii)) return 1 + (b & ((1LL << ii) - 1));
    return 0;
}
*/

int main() {
    ios_base::sync_with_stdio(false);
    freopen("inp", "r", stdin);
    freopen("outp", "w", stdout);
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        lint a, b, k; cin >> a >> b >> k;
/*        k--;
        lint sum = 0;
        for (int i = BITS; i >= 0; i--) {
            if ((k & (1LL << i)) == 0) continue;
            lint sm = (((k >> i) + 1) << i);
            sum += getBound(sm, a - 1) * getBound(sm, b - 1);
        }
        printf("Case #%d: %lld\n", i + 1, a * b - sum);
*/
        int ans = 0;
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++) {
                if ((i & j) < k) ans++;
            }
        printf("Case #%d: %d\n", i + 1, ans);
    }
}
