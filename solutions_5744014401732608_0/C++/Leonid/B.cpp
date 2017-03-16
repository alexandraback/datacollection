#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <list>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)

void openFiles() {
    //freopen("test.in", "rt", stdin);
    //freopen("test.out", "wt", stdout);
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("B-small-attempt0.out", "wt", stdout);
	// freopen("B-large.in", "rt", stdin);
	// freopen("B-large.out", "wt", stdout);
}

void solve() {
	long long b, m;
    cin >> b >> m;
    if (m > (1LL << (b - 2))) {
        printf("IMPOSSIBLE\n");
        return;
    }

    vector<vector<int> > v(b, vector<int>(b, 0));
    REP(i, b) REP(j, b) if (i > 0 && i < b - 1 && i < j) v[i][j] = 1;

    long long r = (1LL << (b - 3));
    for (int k = 1; m > 1; r /= 2, k++) {
        if (m >= r) {
            v[0][k] = 1;
            m -= r;
        }
    }

    if (m > 1) {
        throw 123;
    }

    if (m == 1) {
        v[0][b - 1] = 1;
    }

    printf("POSSIBLE\n");    
    REP(i, b) {
        REP(j, b) printf("%d", v[i][j]);
        printf("\n");
    }

}

int main() {
    openFiles();
    int n; scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
            printf("Case #%d: ", i + 1);
            solve();
    }
    return 0;
}
