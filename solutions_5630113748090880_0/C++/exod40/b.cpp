#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<vector<int>> a;
int b[5000];

void read() {
    scanf("%d", &n);
    a.clear();
    for (int i = 0; i < 2 *n - 1; i++) {
        vector<int> b;
        int x;

        for (int j = 0 ; j < n; j++) {
            scanf("%d", &x);
            b.push_back(x);
        }
        a.push_back(b);
    }
}

void solve() {
    memset(b, 0, sizeof b);
    int srch = n - 1;

    for (int i = 0; i < n - 1; i++) {
        sort(a.begin(), a.end(), [i](vector<int> q, vector<int>w) { return q[i] < w[i]; });

        if (a[2 * i][i] != a[2 * i + 1][i]) {
            srch = i;
            for (int j = 0; j < n; j++) {
                if (j != srch)
                    -- b[a[2 * i][j]];
            }
            break;
        }
    }

    if (srch == n - 1) {
        for (int j = 0; j < n; j++) {
            if (j != srch)
            -- b[ a[2 * n - 2][j] ];
        }
    }

    for (int i = 0; i < 2 * n - 1; i++) {
        b[ a[i][srch] ]++;
    }
    int prnt = 0;
    for (int i = 0; i < 5000; i++) {
        if (b[i] < 0) {
            printf ("error\n");
            exit(1);
        }
        while (b[i] --) {
            if (prnt) printf (" ");
            prnt = 1;
            printf ("%d", i);
        }
    }
    printf ("\n");
}

int main() {
    int cases;

    scanf("%d", &cases);
    for (int i=1; i<=cases; i++) {
        read();
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}

