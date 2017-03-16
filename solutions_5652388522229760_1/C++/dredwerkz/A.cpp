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

int v[10];

#define SINGLELINE 1
void solve() {
    int n = gi();
    if (n == 0) {
        printf("INSOMNIA\n");
        return;
    }
    memset(v, 0, sizeof(v));
    int c = 10, i;
    for (i = 1; c; i++) {
        int m = i*n;
        while (m) {
            int r = m%10;
            m /= 10;
            if (!v[r]) {
                v[r] = 1;
                c--;
            }
        }
    }
    printf("%d\n", (i-1)*n);
}

int main() {
    int t = gi();

    for (int i = 1; i <= t; i++) {
        printf("Case #%d:%c", i, (SINGLELINE ? ' ' : '\n'));
        solve();
        fprintf (stderr, "Case %d / %d. Elapsed %.2f. Estimated %.2f\n", i, t, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / i * t) / CLOCKS_PER_SEC);
    }

    return 0;
}
