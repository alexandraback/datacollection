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
#define R printf("RICHARD\n")
#define G printf("GABRIEL\n")
void solve() {
    int x = gi(), r, c;
    r = gi();
    c = gi();
    if (r < c) {
        int t = r;
        r = c;
        c = t;
    }
    if (r*c%x || x > 2*c) {
        R;
        return;
    }
    if (x <= 3) {
        G;
    } else if (x == 4) {
        if (c == 2)
            R;
        else
            G;
    } else if (x == 5) {
        if (c == 3) {
            if (r == 5)
                R;
            else
                G;
        } else {
            G;
        }
    } else if (x == 6) {
        if (c == 3)
            R;
        else
            G;
    } else {
        R;
    }
}

int main() {
    int t = gi();

    for (int i = 1; i <= t; i++) {
        printf("Case #%d:%c", i, (SINGLELINE ? ' ' : '\n'));
        solve();
    }

    return 0;
}
