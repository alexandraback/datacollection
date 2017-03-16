#define DBG 1

#include <cstring>
#include <map>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> pii;

int gi() {
    int a;
    scanf("%d", &a);
    return a;
}

ll gli() {
    ll a;
    scanf("%lld", &a);
    return a;
}

#define SINGLELINE 1
void solve() {
    int k = gi();
    int c = gi();
    int s = gi();

    if (s * c < k) {
        printf(" IMPOSSIBLE\n");
        return;
    }

    s = k/c + (k%c ? 1 : 0);

    for (int i = 0; i < s; i++) {
        ll b = 1;
        ll res = 1;
        for (int j = i*c; j < (i+1)*c && j < k; j++) {
            res += b*j;
            b *= k;
        }
        printf(" %lld", res);
    }

    printf("\n");
}

int main() {
    int t = gi();

    for (int i = 1; i <= t; i++) {
        printf("Case #%d:", i);
        solve();
        fprintf (stderr, "Case %d / %d. Elapsed %.2f. Estimated %.2f\n", i, t, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / i * t) / CLOCKS_PER_SEC);
    }

    return 0;
}
