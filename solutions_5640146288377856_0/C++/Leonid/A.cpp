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
using namespace std;

void openFiles() {
#ifndef ONLINE_JUDGE
    freopen("A-small-attempt0.in", "rt", stdin);
    freopen("A-small-attempt0.out", "wt", stdout);
#endif
}

void solve() {
	int n, m, w; scanf("%d %d %d ", &n, &m, &w);
    int r = 0, k = 0;
    vector<int> v;    
    for (int i = -1; i < m; i += w + 1) {
        int q = min(w, m - i - 1);
        if (q >= w) {
            v.push_back(q);
        }
        if (i >= 0) {
            r++;
        }
    }
    r += v.size() - 1;
    r += w;
    cout << r << endl;
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
