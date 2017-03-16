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

int aa[52][52];

#define SINGLELINE 1
void solve() {
    int n = gi();
    ll m = gli();

    ll a = 1LL << (n-2);

    if (m > a) {
        printf("IMPOSSIBLE\n");
        return;
    }
    printf("POSSIBLE\n");
    memset(aa, 0, sizeof(aa));

    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n-1; j++)
            aa[i][j] = 1;

    m--;
    aa[0][n-1] = 1;
    int ii = 1;
    while (m) {
        if (m%2)
            aa[ii][n-1] = 1;
        ii++;
        m /= 2;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d", aa[i][j]);
        printf("\n");
    }
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
